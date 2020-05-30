#include <iostream>
#include <string>

using namespace std;


class A
{
public:
  int i_ = 0;

  void func(int x, int y)
  {
    //auto x1 = []{return i_;}; //error 没有捕获外部变量
    auto x2 = [=]{return i_+x+y;}; //捕获外部所有变量
    auto x3 = [&]{return i_+x+y;}; //捕获外部所有变量
    auto x4 = [this]{return i_;}; //捕获this指针
    //auto x5 = [this]{return i_+x+y;}; //错误没有捕获x和y
    auto x6 = [this, x, y]{return i_+x+y;};
    auto x7 = [=] ()mutable {return i_++;}; //当内部发送改变，外部也同样发生改变
  }

};

int main(int argc, char** argv)
{

  auto f = [](int a)->int{ return a+1;}; //标准lambda写法

  auto x1 = [](int i){return i;}; //返回值为int 可以自动推导

  typedef void(*Ptr)(int*); //定义函数指针
  Ptr p = [](int* p){delete p;}; //正确，没有捕获任何变量
  //Ptr p1 = [&](int *p){delete p;}; //错误，有this指针不能直接转换为函数指针


  //auto x2=[](){ {1,2};}; //返回值类型无法推导，初始化列表不能用于返回值的自动推导

  std::cout<<f(1)<<std::endl;













  return 0;
}