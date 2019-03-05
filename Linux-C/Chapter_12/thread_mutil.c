#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#define NUM_THREAD 6
void *thread_function(void * arg);
int main()
{
	int res ;
	pthread_t a_thread[NUM_THREAD];
	void *thread_result;
	int lots_of_threads;
	
	for(lots_of_threads=0 ; lots_of_threads < NUM_THREAD;lots_of_threads++)
	{
		res = pthread_create(&(a_thread[lots_of_threads]),NULL,thread_function,(void *)&lots_of_threads);
		if(res != 0 )
		{
			perror("Thread creation failed");
			exit(EXIT_FAILURE);
		}
		sleep(1);
	}
	printf("Waiting for threads to finish... \n");
	for(lots_of_threads=NUM_THREAD-1;lots_of_threads>=0;lots_of_threads--)
	{
		res = pthread_join(a_thread[lots_of_threads],&thread_result);
		if(res == 0 )
		{
			printf("Picked up a thread \n");
		}
		else
		{
			perror("pthread_join failed");
		}
	}

	printf("All done \n");
	exit(EXIT_SUCCESS);
}

void *thread_function(void * arg)
{
	int my_number = *(int *)arg;
	int read_num;
	
	printf("thread_function is running ,Argument was %d\n",my_number);
	read_num=1+(int)(9*rand()/(RAND_MAX+1.0));
	sleep(read_num);
	printf("Bye from %d\n",my_number);
	pthread_exit(NULL);
}
