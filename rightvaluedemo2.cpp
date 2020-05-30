#include <iostream>
#include <typeinfo>
#include <string>
#ifndef _MSC_VER
#include <cxxabi.h>
#endif

using namespace std;

class A
{
public:
  A():m_ptr(new int(0))
  {
    std::cout<<"construct"<<std::endl;
  }
  A(const A& a):m_ptr(new int(*a.m_ptr)) //深拷贝
  {
    cout<<"copy construct"<<std::endl;
  }

  //移动构造
  A(A&& a):m_ptr(a.m_ptr)
  {
    a.m_ptr = nullptr;
    cout<<"move construct"<<endl;
  }

  ~A()
  {
    cout<<"destruct"<<endl;
    delete m_ptr;
  }
private:
  int *m_ptr;
};

A Get(bool flag)
{
  A a;
  A b;
  if(flag)
   return a;
  else 
   return b;
}

int main(int argc ,char** argv)
{

  A a = Get(false); //运行正确
  return 0;
}