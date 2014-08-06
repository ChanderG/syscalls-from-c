//ChanderG - 29/07/14 - chandergovind@gmail.com
//The C code with inline assembly


#define BUFF 20
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
