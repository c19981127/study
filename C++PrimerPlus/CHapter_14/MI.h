#ifndef _MI_H_
#define _MI_H_
class father
{
private:
  int age;
public:
  father();
  father(int age_);
  void set_age(int age_);
  virtual void show();
  virtual ~father();
};
class son_one : public father
{
public:
  son_one();
  son_one(int age_);
  void set_age(int age_);
  void show();
  ~son_one();
};
class son_two : public father
{
public:
  son_two();
  son_two(int age_);
  void set_age(int age_);
  void show();
  ~son_two();
};
class son_son : public son_one , public son_two
{
public:
  son_son();
  son_son(int age_);
  void set_age(int age_);
  void show();
  ~son_son();
};
#endif
