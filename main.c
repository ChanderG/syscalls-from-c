#include <stdio.h>
#include <stdlib.h>
#include "myl.h"

void testPrinti(){
  int n;
  printf("****Testing printi****\n");
  printf("Enter an integer: ");
  scanf("%d", &n);
  int nos = printi(n);
  //printing twice to see if no space  
  //printi(n);
  printf("\n# of digits: %d\n", nos);
}

void testPrints(){
  char name[25];
  printf("****Testing prints****\n");
  printf("Enter your name: ");
  //scanf("%s", name);
  gets(name);
  int nos = prints(name);
  //printing twice to see if no space  
  //printi(n);
  printf("\n# of digits: %d\n", nos);
}

void testReadi(){
  printf("****Testing readi****\n");
  //printf("Enter a number: ");
  int *e = (int *) malloc(sizeof(int));
  int sign = readi(e);
  printf("%d",sign);
  printf("\nIt is ERR(1) OK(0) --- %d",*e);
}


void testReadf(){
  printf("****Testing readf****\n");
  //printf("Enter a number: ");
  float *f = (float *) malloc(sizeof(float));
  int sign = readf(f);
  printf("%f",*f);
  printf("\nIt is ERR(1) OK(0) --- %d",sign);
}

void testPrintd(){
  float n;
  printf("****Testing printd****\n");
  printf("Enter an float: ");
  scanf("%f", &n);

  //try this to compare w/ printf
  printf("%f\n", n);

  int nos = printd(n);
  //printing twice to see if no space  
  //printi(n);
  printf("\n# of digits: %d\n", nos);
}

int main()
{
  //testPrinti(); tested OK
  //testPrints(); tested OK
  //testReadi();  tested OK
  //testReadf();  tested MEDIUM
  testPrintd();   //tested Medium
  return 0;

}
