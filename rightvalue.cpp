#include <iostream>

#include <string>

using namespace std;

int g_constructCount=0;
int g_copyConstructCount = 0;
int g_destructCount = 0;

struct A
{
  A()
  {
    cout<<"const struct "<<++g_constructCount<<endl;
  }
  A(const A&a)
  {
    cout<<"copy struct"<<++g_copyConstructCount<<endl;
  }
  ~A()
  {
    cout<<"destruct: "<<++g_destructCount<<endl;
  }
};

A GetA()
{
  return A();
}

template<typename T> 
void f(T&& para)
{
  std::cout<<"hello world"<<std::endl;
}

void PrintValue(int &i)
{
  std::cout<<"lvalue: "<<i<<std::endl;
}

void PrintValue(int&& i)
{
  std::cout<<"rvalue: "<<i<<std::endl;
}

void Forward(int&&i)
{
  PrintValue(i);
}


void test01()
{
  int i = 0;
  PrintValue(i);
  PrintValue(1); //右值引用
  Forward(2); //本来是一个右值，进入函数之后成为左值
}

void test()
{
  f(10); //这是一个右值
  int x = 10;
  f(x); //这是一个左值

  A&& a = GetA();
  const A& b = GetA(); //常量左值引用可以接收所有的左右值类型 
  
  int w1, w2;
  auto v1 = w1;
  decltype(w1)&& v2 = std::move(w2);
  //decltype(w1)&& v3 = w2; //错误，左值无法直接赋值给右值引用
}

int main()
{

  test01();
  return 0;
}