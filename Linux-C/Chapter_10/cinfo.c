#include <stdio.h>
#include <stdlib.h>
int main()
{
	#ifdef DEBUG
		printf("Compiled :" __DATE__ "at" __TIME__ "\n");
		printf("this is line %d of file %s\n",__LINE__,__FILE__);
	#endif
	printf("Hello World !!! \n");
	exit(EXIT_SUCCESS);
}
