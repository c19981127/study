#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>
#define WORK_SIZE 1024
void *thread_function(void *arg);
sem_t bin_sem;
char work_area[WORK_SIZE];

int main()
{
	int res;
	pthread_t  a_pthread;
	void *thread_result;
	
	res = sem_init(&bin_sem,0,0);
	if(res != 0)
	{
		perror("Samaphore initialzation failed \n");
		exit(EXIT_FAILURE);
	}
	res = pthread_create(&a_pthread,NULL,thread_function,NULL);
	if(res != 0)
	{
		perror("Thread creationg failed \n");
		exit(EXIT_FAILURE);
	}
	printf("Input some text . Enter 'end' to finish \n");
	while(strncmp("end",work_area,3) != 0)
	{
		fgets(work_area,WORK_SIZE,stdin);
		sem_post(&bin_sem);
	}
	printf("\n Waiting for thread to finish ... \n");
	res = pthread_join(a_pthread,&thread_result);
	if(res != 0)
	{
		perror("Thread join failed \n");
		exit(EXIT_FAILURE);
	}
	printf("thread joined \n");
	sem_destroy(&bin_sem);
	exit(EXIT_SUCCESS);
}

void *thread_function(void *arg)
{
	sem_wait(&bin_sem);
	while(strncmp("end",work_area,3)!= 0)
	{
		printf("You input %d characters \n",strlen(work_area)-1);
		sem_wait(&bin_sem);
	}
	pthread_exit(NULL);
}
