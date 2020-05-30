#include <iostream>
#include <functional>

using namespace std;

void func(void)
{
  cout<< __FUNCTION__<<endl;
}

//function 实现回调
class A
{
  std::function<void()> callback_;
public:
  A(const std::function<void()>& f) //传入函数
      :callback_(f)
      {

      }
  void notify(void)
  {
    callback_(); //回调到上层
  }
};


class Foo
{
public:
  static int foo_func(int a) //静态成员函数，不传入this
  {
    std::cout<<__FUNCTION__<<"("<<a<<") ->: ";
    return a;
  }

  void operator()(void)
  {
    std::cout<<__FUNCTION__<<std::endl;
  }
};

class Bar
{
public:
  int operator()(int a) //仿函数 
  {
    std::cout<<__FUNCTION__<<"("<<a<<") ->: "<<this;
    return a;
  }
};


void call_when_even(int x,const std::function<void(int)>& f) //function 作为函数参数传递
{
  if(!(x & 1)) //x%2==0
  {
    f(x);
  }
}

void output(int x)
{
  std::cout<<x<<" ";
}

int main(void)
{
  for(int i = 0; i<10;++i)
  {
    call_when_even(i,output);
  }

  Foo foo;
  A aa(foo); //传入foo仿函数
  aa.notify();

  std::function<void(void)> fr1 = func; //绑定一个普通函数
  fr1();

  //绑定一个类的静态成员函数
  std::function<int(int)> fr2 = Foo::foo_func;
  std::cout<<fr2(123)<<endl;

  Bar bar;
  fr2 = bar;    //绑定一个仿函数
  std::cout<<fr2(123)<<endl;
  return 0;
}