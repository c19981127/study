#include <unistd.h>
#include <stdio.h>
int main()
{
	pid_t fpid;
	static int count = 0;
	fpid =fork();
	if(fpid < 0)
		printf("error in fork");
	if(fpid == 0)
	{
		printf("Forking  sucessful and this is the new process");
		printf("    %d \n",getpid());
		count++;
	}
	else
	{
		printf("this is the parent process");
		printf("    %d\n",getpid());
		count++;
	}
	printf("the count now is %d \n",count);
	return 0;
}
