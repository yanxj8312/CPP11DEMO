#include <iostream>
#include <string>

using namespace std;

//auto 的用法和 推导方式

//void func(auto a =1){} //错误 auto不能用于函数参数

struct foo
{
  //auto var1 = 0;    //不能用于非静态成员变量
  static const auto var2 = 0; //只有静态成员常量才能成功推到
};

//template <typename T>
//struct Bar{};

class Foo
{
public:
  static int get(void)
  {
    return 1;
  }
};

class Bar
{
public:
  static const char* get(void)
  {
    return "0";
  }
};

template <typename T>
void func(void)
{
  auto val = T::get();
  cout<<val<<endl;
}



int main(int argc, char** argv)
{
  auto x = 5; //x为int类型
  auto pi = new auto(1);  //pi被推导为int*
  const auto *v = &x,u=6;   //v是const int*类型，u是const int类型
  static auto y = 0.0;    //y是double类型
  
  func<Foo>();
  func<Bar>();


  //Bar<auto> bb = bar;     //auto 无法推到出模板参数

  //auto rr[10]={0};    //auto无法定义数组
  //auto int r;     //auto不在表示存储类型符号
  //auto s;   //auto 无法推到类型
  //auto 不能作为函数参数
  return 0;
}
