// we use this program to recice CTRL+C and solve it
// in this program we have to use CTRL+\ to stop it
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
void ouch(int sig)
{
	printf("OUCH! - I got signal %d \n",sig);
}
int main()
{
	
	struct sigaction act;
	act.sa_handler = ouch;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;

	sigaction(SIGINT,&act,0);
	while(1)
	{
		printf("Hello World \n");
		sleep(1);
	}
	exit(0);
}
