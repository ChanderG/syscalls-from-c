#include <stdio.h>
#include "myl.h"
int main()
{
	int n;
	printf("****Testing printi****\n");
	printf("Enter an integer: ");
	scanf("%d", &n);
	int nos = printi(n);
  //printing twice to see if no space	
	//printi(n);
	printf("\n# of digits: %d\n", nos);
	return 0;
}
