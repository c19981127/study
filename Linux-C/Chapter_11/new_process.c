#include <stdlib.h>
#include <stdio.h>
int main()
{
	printf("Running ps with system \n");
	system("ps -aux");
	printf("Done \n");
	exit(0);
}
