#include <iostream>

using namespace std;

template <typename T>
void PrintT(T & t)
{
  cout<<"lvalue "<<t<<endl;
}

template <typename T>
void PrintT(T &&t)
{
  cout<<"rvalue "<<t<<endl;
}

template <typename T>
void TestForward(T&& v)
{
  PrintT(v); //右值引用
  PrintT(std::forward<T>(v)); //右值引用 
  PrintT(std::move(v)); //右值引用
}

void test()
{
  TestForward(1);
  int x = 1;
  TestForward(x);
  TestForward(std::forward<int>(x));
}

int main(void)
{
  test();
  return 0;
}