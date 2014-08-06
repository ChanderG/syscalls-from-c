#include <stdio.h>
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
int main()
{
	testPrints();
	return 0;
}
