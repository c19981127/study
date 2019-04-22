#include <iostream>
#include <cstdlib>
#define MAXSIZE 50
typedef struct
{
  int data[MAXSIZE];
  int length;
}sort_list;
void init_list(sort_list *& list);
void insert_list(sort_list *& list,int value,int n);
void delete_list(sort_list *& list,int value);
bool find(sort_list * list ,int value);
void show(sort_list * list);
int main()
{
  sort_list * list;
  init_list(list);
  insert_list(list, 200, 5);
  delete_list(list, 5);
  show(list);
  if(find(list,200))
    std::cout<<"the number has been found in the list"<<std::endl;
  else
    std::cout<<"the number is not in the list"<<std::endl;
}
void init_list(sort_list *& list)
{
  list = (sort_list *)malloc(sizeof(sort_list));
  if(list == NULL)
  {
    std::cout<<"the init is failed "<<std::endl;
    exit(1);
  }
  for(int i =0; i<20;i++)
    list->data[i] = i+1;
  list->length = 20;
}
void insert_list(sort_list *& list, int value , int n)
{
  if(n<1 || n > list->length)
  {
    std::cout<<"wrong position insert failed"<<std::endl;
    exit(1);
  }
  for(int i =list->length-1;i>=n-1;i--)
  {
    list->data[i+1]=list->data[i];
  }
  list->data[n-1] = value;
  list->length++;
}
void delete_list(sort_list *& list ,int value)
{
  int count = 0;
  for(int i =0 ;i<list->length;i++)
  {
    if(list->data[i] == value )
    {
      count ++;
      list->data[i+1-count] = list->data[i+1];
    }
    else
    {
      list->data[i-count] = list->data[i];
    }
  }
  list->length = list->length - count;
}
bool find(sort_list * list ,int value)
{
  for(int i = 0; i <list->length;i++)
  {
    if(list->data[i] == value)
      return true;
  }
  return false;
}
void show(sort_list * list)
{
  for(int i =0 ;i<list->length;i++)
  {
    std::cout<<list->data[i]<<" ";
    if((i+1)%10 == 0)
      std::cout<<std::endl;
  }
  std::cout<<std::endl;
}
