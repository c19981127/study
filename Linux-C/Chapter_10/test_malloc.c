#include <stdio.h>
#include <stdlib.h>
int main()
{
	char *ptr = (char *)malloc(1024);
	ptr[0] = 0;
	
	//now write to the end of the block
	ptr[1024] = 0;
	exit(EXIT_SUCCESS);
}
