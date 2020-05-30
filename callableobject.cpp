#include <iostream>

using namespace  std;


void func(void)
{
  printf("hello world\n");
}

struct Foo
{
  void operator()(void) //仿函数
  {
    printf("operaotor () \n");
  }
};

struct Bar
{
  using fr_t =void(*)(void); //函数指针
  static void func(void)
  {
    printf("bar func\n");
  }

  operator fr_t(void)
  {
    return func;
  }
};


struct A
{
  int a_;
  void mem_func(void)
  {
    printf("mem_func \n");
  }
};

int main(int arg,char **argv)
{
  void(*func_ptr)(void) = &func; //函数指针

  func_ptr(); //调用函数

  Foo foo;
  foo();  //仿函数调用

  Bar bar;
  bar(); //可以被转换为函数指针的类对象

  void (A::*mem_func_ptr)(void) = &A::mem_func; //类成员函数指针

  int A::*mem_obj_ptr = &A::a_; //类成员指针

  A aa;
  (aa.*mem_func_ptr)(); //类成员函数调用

  aa.*mem_obj_ptr = 123; //类成员指针调用


  return 0;
}