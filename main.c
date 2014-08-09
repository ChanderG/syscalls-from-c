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
	//printf("\n# of digits: %d\n", nos);
}

void testReadi(){
	printf("****Testing readi****\n");
	//printf("Enter a number: ");
	int *e = (int *) malloc(sizeof(int));
	int sign = readi(e);
	printf("%d",sign);
}

int main()
{
  testReadi();
	return 0;
}
