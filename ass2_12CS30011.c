//ChanderG - 29/07/14 - chandergovind@gmail.com
//The C code with inline assembly

#include "myl.h"
#define BUFF 20

//special case zero for all functions

int printi(int n){
  char buff[BUFF], zero='0';
  int i=0,j, k, bytes;

  if(n == 0) buff[i++]=zero;
  else{
    if(n < 0) {
      buff[i++]='-';
      n = -n;
    }
    while(n){
      int dig = n%10;
      buff[i++] = (char)(zero+dig);
      n /= 10;
    }
    if(buff[0] == '-') j = 1;
    else j = 0;
    k=i-1;
    while(j<k){
      char temp=buff[j];
      buff[j++] = buff[k];
      buff[k--] = temp;
    }
  } 
  bytes = i;

  __asm__ __volatile__ (
      "movl $4, %%eax \n\t"
      "movl $1, %%ebx \n\t"
      "int $128 \n\t"
      :
      :"c"(buff), "d"(bytes)
      ) ;  // $4: write, $1: on stdin

  return bytes;    
}

//has size limitation
int prints(char* c){
  int n = 0; 
  while(*c != '\0'){
  __asm__ __volatile__ (
      "movl $4, %%eax \n\t"
      "movl $1, %%ebx \n\t"
      "int $128 \n\t"
      :
      :"c"(c), "d"(1)
      ) ;  // $4: write, $1: on stdin
  c++;
  n++;
  }
  return n;
}


//In case of int overflow returns an error condition
int readi(int *eP){  // *eP is for error, if the input is not an integer
  char buff[BUFF];
  __asm__ __volatile__ (
      "movl $3, %%eax \n\t"
      "movl $0, %%ebx \n\t"
      "int $128 \n\t"
      :
       :"c"(buff), "d"(BUFF)
      ) ;  // $3: read, $1: on stdin
  int mult = 1;
  int i = 0;
  if(buff[0] == '-'){ mult = -1; i++; }
  int ans = 0;
  int dig;
  char zero = '0';

  for(;buff[i] != '\0';i++){
    if(buff[i] == '\n') continue;
    dig = buff[i] - zero;
    if((dig < 0) || (dig > 9)){
      //error case  ERR = 1
      *eP = 1;  
      return -1;
    }
    else{
      ans = 10*ans + dig;   
    } 
  }
  ans *= mult;
  *eP = 0;  
  return ans;
}

//alpha testing phase
//Issues:
//numbers are approximate sometimes 

int readf(float *f){  // return value is error or OK
  char buff[BUFF];
  __asm__ __volatile__ (
      "movl $3, %%eax \n\t"
      "movl $0, %%ebx \n\t"
      "int $128 \n\t"
      :
       :"c"(buff), "d"(BUFF)
      ) ;  // $3: read, $1: on stdin

  int mult = 1;
  int i = 0;
  if(buff[0] == '-'){ mult = -1; i++; }
  float ans = 0;
  int dig;
  char zero = '0';
  int mode = 0;   //0 - before . ; 1 - after
  int div = 1; 
  float subsum;
  int j;

  for(;buff[i] != '\n';i++){
    //if(buff[i] == '\n') continue;
    if((mode == 0) && (buff[i] == '.')){ mode = 1; continue; }
    dig = buff[i] - zero;
    if((dig < 0) || (dig > 9)){
      //error case  ERR = 1
      *f = -1;  
      return 1;
    }
    else{
      if(mode == 0)
        ans = 10*ans + dig;   
      else{
        //divide by div and add it; also increace div value
        //kinda inefficient

        subsum = dig;
        for(j = 0;j < div;j++) subsum = subsum/10.0;
        ans += subsum; 
        div += 1;
      }
    } 
  }
  if (mode == 0) ans *= 1.0;
  ans *= mult;
  *f = ans;  
  return 0;
}

//alpha testing
//issues
//wrong precision shown
//artificial limit on precision
//approxiamtions are done

//Corner cases:
//3.303

//the function is named printd, change it to printf if needed.
int printd(float in){
  char buff[BUFF];
  int i = 0;
  char zero = '0';
  int neg = 1;

  if(in == 0) { buff[i] = zero; i++;}
  if(in < 0) { buff[i] = '-'; i++; neg = -1;}
   
  in *= neg;  

  int pre = in; 
  int start = i;    

  while(pre){
    int dig = pre%10;
    buff[i++] = (char)(zero+dig);
    pre /= 10;
  }
    
  int j = start;
  int k = i-1;
  while(j<k){
    char temp=buff[j];
    buff[j++] = buff[k];
    buff[k--] = temp;
  }

  float rem = in - ((int)in)*(1.0);
  int pre2;

  int count = 0; //for closing deal within 5-6 digits 

  if( rem != 0){

    buff[i] = '.';
    i++;

    while(rem != 0){
      rem *= 10;
      pre2 = rem;
      buff[i] = (char)(pre2 + zero);
      i++;
      rem = rem - ((int)rem)*(1.0);
      count++;
      if(count > 5) break;                   // cut point, we stop after reading 5+1 digits
    }
  }

  __asm__ __volatile__ (
      "movl $4, %%eax \n\t"
      "movl $1, %%ebx \n\t"
      "int $128 \n\t"
      :
      :"c"(buff), "d"(i)
      ) ;  // $4: write, $1: on stdin
  return i;
}
