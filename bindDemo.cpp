#include <iostream>
#include <functional>

using namespace std;

void call_when_even(int x,const std::function<void(int)> &f)
{
  if(!(x & 1))
  {
    f(x);
  }
}

void output(int x)
{
  std::cout<<x<<" ";
}

void output_add_2(int x)
{
  std::cout<<x+2<<" ";
}

class A
{
public:
  int i_ = 0;
  void output(int x,int y)
  {
    std::cout<<x<<" "<<y<<std::endl;
  }
};

int main(void)
{
  A a;
  std::function<void(int,int)> fr = std::bind(&A::output,&a,std::placeholders::_1,std::placeholders::_2); //bind+function进行函数回调

  fr(1,2);

  std::function<int&(void)> fr_i = std::bind(&A::i_,&a);
  fr_i() = 123;
  std::cout<<a.i_<<std::endl;

  {
    auto fr = std::bind(output,std::placeholders::_1); //绑定函数和占位符用来进行调用
    for(int i = 0; i < 10; i++)
    {
      call_when_even(i,fr);
    }
    std::cout<<std::endl;
  }

  {
    auto fr = std::bind(output_add_2,std::placeholders::_1);
    for(int i = 0; i < 10; i++)
    {
      call_when_even(i,fr);
    }
    std::cout<<std::endl;
  }
}