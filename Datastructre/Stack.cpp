#include <iostream>
#include <cstdlib>
#define MAXSIZE 50
typedef struct
{
  int data[MAXSIZE];
  int top;
}stack;
void init_stack(stack *& s);
void push(stack * & s, int value);
int pop(stack *& s);
bool isEmpty(stack * s);
bool isFull(stack * s);
void show(stack *s);
int main()
{
  stack * list;
  init_stack(list);
  show(list);
  std::cout<<pop(list)<<std::endl;
  show(list);
  push(list,100);
  show(list);
}
void init_stack(stack *& s)
{
  s = (stack * )malloc(sizeof(stack));
  for(int i=1;i<11;i++)
  {
    s->data[i-1]=i;
  }
  s->top=10;
}
bool isEmpty(stack * s)
{
  if(s->top == 0)
    return true;
  return false;
}
bool isFull(stack * s)
{
  if(s->top == MAXSIZE)
    return true;
  return false;
}
void push(stack *& s,int value)
{
  if(isFull(s))
  {
    std::cout<<"the stack is full ,push failed"<<std::endl;
    exit(1);
  }
  s->data[s->top]=value;
  s->top++;
}
int pop(stack * &s)
{
  if(isEmpty(s))
  {
    std::cout<<"the stack is Empty pop failed"<<std::endl;
    exit(1);
  }
  s->top--;
  return s->data[s->top];
}
void show(stack * s)
{
  int temp;
  int temp_s = s->top;
  while(!isEmpty(s))
  {
    temp = pop(s);
    std::cout<<temp<<" ";
  }
  std::cout<<std::endl;
  s->top=temp_s;
}
