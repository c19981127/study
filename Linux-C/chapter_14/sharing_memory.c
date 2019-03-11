//this file will create sharing-memories and show the datas in it
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/sem.h>
#include "sharing_memories.h"
int main()
{
  int running = 1;
  void *shared_memory = (void *)0;
  struct sharing_memories *shared_stuff;
  int shmid ;
  srand((unsigned int)getpid());

  shmid = shmget((key_t)1234,sizeof(struct sharing_memories),0666|IPC_CREAT);// cteate some sharing_memories
  if(shmid == -1)
  {
    fprintf(stderr,"shmget failed \n");
    exit(EXIT_FAILURE);
  }

  shared_memory = shmat(shmid,(void *)0,0);//make sharing_memories useful
  if(shared_memory == (void *) -1)
  {
    fprintf(stderr,"shmat failed \n");
    exit(EXIT_FAILURE);
  }
  printf("Memori attached at %X \n",(int)shared_memory);

  shared_stuff = (struct sharing_memories *)shared_memory;
  shared_stuff->written_by_you = 0;
  while(running)
  {
    if(shared_stuff->written_by_you)
    {
      printf("You wrote: %s",shared_stuff->some_text);
      sleep(rand() %4);
      shared_stuff->written_by_you = 0;
      if(strncmp(shared_stuff->some_text,"end",3) == 0)
      {
        running = 0;
      }
    }
  }

  if(shmdt(shared_memory) == -1)   //part the sharing_memories from the process
  {
    fprintf(stderr,"shmdt failed \n");
    exit(EXIT_FAILURE);
  }
  if(shmctl(shmid,IPC_RMID,0) == -1)//shmctl (control function of memories) IPC_RMID means "delete"
  {
    printf(stderr,"shmctl(IPC_RMID) failed \n");
    exit(EXIT_FAILURE);
  }
  exit(EXIT_SUCCESS);
}
