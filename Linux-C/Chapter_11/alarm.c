#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
static int alarm_fired = 0;

void ding(int sig)
{
	alarm_fired = 1;
}

int main()
{
	pid_t pid;
	printf("alarm application starting \n");
	
	pid = fork();
	switch(pid)
	{
		case -1:
			perror("Fork failed");
			exit(1);
			break;
		case  0:
			sleep(5);
			kill(getppid(),SIGALRM);
			exit(0);
			break;
		default:
			break;
	}
	printf("waiting fot alarm to go off\n");
	(void) signal(SIGALRM,ding); //when get SIGALRM signal exec function ding

	pause();
	if(alarm_fired)
		printf("Ding \n");
	printf("Done \n");
	exit(0);
}
			
