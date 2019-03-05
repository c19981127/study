// use command "gcc -D_REENTRANT thread1.c -o thread1 -lpthread" to compile this program
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
int run_now =1;
void *thread_function(void *arg);
char message[] = "Hello World";

int main()
{
	int res;
	pthread_t a_thread;

	res = pthread_create(&a_thread,NULL,thread_function,(void *)message);
	if(res != 0)
	{
		perror("Thead creation failed \n");
		exit(EXIT_FAILURE);
	}
	int print_count2 = 0;
	while(print_count2++ < 20)
	{
		if(run_now == 1)
		{
			printf("1 \n");
			run_now=2;
		}
		else
		{
			sleep(1);
		}
	}
	exit(EXIT_SUCCESS);
}

void *thread_function(void *arg)
{
	int print_count2 = 0;
	while(print_count2++ < 20)
	{
		if(run_now == 2)
		{
			printf("2\n");
			run_now=1;
		}
		else
		{
			sleep(1);
		}
	}
}	
