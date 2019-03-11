// use command "gcc -D_REENTRANT thread1.c -o thread1 -lpthread" to compile this program
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
void *thread_function(void *arg);
int main()
{
	int res;
	pthread_t a_thread;
	void *thread_result;

	res = pthread_create(&a_thread,NULL,thread_function,NULL);
	if(res != 0)
	{
		perror("Thead creation failed \n");
		exit(EXIT_FAILURE);
	}
	sleep(3);
	printf("Canceling thread...\n");
	res = pthread_cancel(a_thread);
	if(res != 0)
	{
		perror("Thread canceltion failed \n");
		exit(EXIT_FAILURE);
	}	
	printf("Waiting  for thread to finish ....\n");

	res = pthread_join(a_thread,&thread_result);
	if(res != 0)
	{
		perror("Thread join failed \n");
		exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);
}

void *thread_function(void *arg)
{
	int i ,res;
//cancel_enable
	res = pthread_setcancelstate(PTHREAD_CANCEL_ENABLE,NULL);
	if(res != 0)
	{
		perror("Thread pthread_setcancelstate failed ");
		exit(EXIT_FAILURE);
	}
//cancel_deferred
	res = pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED,NULL);
	if(res != 0)
	{
		perror("Thread pthread_setcanceltype failed");
		exit(EXIT_FAILURE);
	}
	printf("thread_function is running \n");
	for(i = 0; i<10; i++)
	{
		printf("Thread is still running (%d) \n",i);
		sleep(1);
	}
	pthread_exit(0);
}
