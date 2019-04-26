#include <iostream>
#include <cstdlib>
#define MAXSIZE 50
typedef struct
{
  int data[MAXSIZE];
  int front,tail;
}sortQueue;
bool isEmpty(sortQueue * list);
bool isFull(sortQueue * list);
void init(sortQueue * & list);
void push(sortQueue *& list,int value);
void pop(sortQueue *& list);
void show(sortQueue * list);
int main()
{
  sortQueue * list;
  init(list);
  show(list);
  for(int i =20 ;i <=50;i++)
    push(list,i*100);
  show(list);
  for(int i = 0; i<29;i++)
    pop(list);
  show(list);
}
bool isEmpty(sortQueue * list)
{
  if(list->tail == list->front-1)
    return true;
  return false;
}
bool isFull(sortQueue * list)
{
  if(list->tail - list->front == MAXSIZE -1)
    return true;
  return false;
}
void init(sortQueue * &list)
{
  list = (sortQueue *)malloc(sizeof(sortQueue));
  list->front =0;
  list->tail = 0;
  list->data[list->tail]=100;
}
void push(sortQueue *& list ,int value)
{
  if(isFull(list))
  {
    std::cout<<"the queue is full now ,push failed"<<std::endl;
    exit(1);
  }
  list->tail ++;
  list->data[list->tail]=value;
}
void pop(sortQueue *& list)
{
  if(isEmpty(list))
  {
    std::cout<<"the queue is Empty now , pop failed"<<std::endl;
    exit(1);
  }
  list->front++;
}
void show(sortQueue * list)
{
  if(isEmpty(list))
  {
    std::cout<<"the queue is empty, show failed"<<std::endl;
    return ;
  }
  for(int i=list->front;i<=list->tail;i++)
  {
    std::cout<<"the number "<<i-list->front+1<<" data is "<<list->data[i%MAXSIZE]<<std::endl;
  }
  std::cout<<std::endl;
}
