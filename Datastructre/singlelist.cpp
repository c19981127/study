#include <iostream>
#include <cstdlib>
struct s_list
{
  int data;
  struct s_list * next;
};
void init_list(s_list *& list);
void add(s_list *& list ,int value);
void insert(s_list *& list,int value,int n);
void delete_position(s_list *& list,int n);
void delete_value(s_list *& list,int value);
void show(s_list * list);
int main()
{
  s_list * list;
  init_list(list);
  show(list);
  add(list,200);
  show(list);
  insert(list,300,2);
  show(list);
  delete_position(list, 1);
  show(list);
  delete_value(list,300);
  show(list);
}
void init_list(s_list * & list)
{
  list = (s_list *)malloc(sizeof(s_list));
  list->data = 100;
  list->next = NULL;
}
void add(s_list *& list ,int value)
{
  s_list * temp = (s_list *)malloc(sizeof(s_list));
  temp->data = value;
  temp->next = NULL;
  s_list * test = list;
  for(;test->next!= NULL;test = test->next)
  {
    ;
  }
  test->next = temp;
}
void insert(s_list *& list ,int value,int n)
{
  s_list * temp = list;
  if(n == 1)
  {
    s_list * add = (s_list *)malloc(sizeof(s_list));
    add->data = value;
    add->next = temp;
    list = add;
  }
  else
  {
    for(int i =0 ;i < n-2;i++)
    {
      if(temp->next == NULL)
      {
        std::cout<<"the number N is too large"<<std::endl;
        exit(1);
      }
      temp = temp->next;
    }
    s_list * add = (s_list *)malloc(sizeof(s_list));
    add->data = value;
    add->next = temp->next;
    temp->next=add;
  }
}
void delete_position(s_list * &list ,int n)
{
  s_list * temp = list;
  if(n==1)
  {
    if(list->next == NULL)
      list->data = -1;
    else
      list = list->next;
  }
  else
  {
    for(int i =0 ;i<n-2;i++)
    {
      if(temp->next == NULL)
      {
        std::cout<<"the number N is too large"<<std::endl;
        exit(1);
      }
      temp =temp->next;
    }
  }
  temp->next = temp->next->next;
}
void delete_value(s_list *& list ,int value)
{
  if(list->data == value)
  {
    if(list->next != NULL)
      list = list->next;
    else
      list->data = -1;
  }
  for(s_list * temp = list;temp->next!= NULL;temp = temp->next)
  {
    if(temp->next->data == value)
      {
        temp->next = temp->next->next;
      }
  }
}
void show(s_list * list)
{
  for(;list != NULL;list = list->next)
    std::cout<<list->data<<" ";
  std::cout<<std::endl;
}
