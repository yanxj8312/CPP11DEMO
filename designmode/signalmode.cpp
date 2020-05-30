#include <iostream>

//单例模式
//创建单例模式的步骤
//构造函数私有化
//增加静态私有的当前类的指针变量
//提供静态对外接口，可以让用户获得单例对象
using namespace std;

class A
{
public:
  static A* getInstance()
  {
    return a;
  }

private:
 A();
 static A* a ;
};

A* A::a= nullptr;

class Singleton_lazy //懒汉模式 线程不安全
{
private:
  Singleton_lazy(){}
  static Singleton_lazy* pSignleton;

public:
  static Singleton_lazy* getInstance() {
    if(pSignleton == nullptr)
    {
      pSignleton = new Singleton_lazy;
    }
    return pSignleton;
  }
};
//程序运行时才开始创建
Singleton_lazy* Singleton_lazy::pSignleton = nullptr;


class Singleton_hungry //饿汉模式 多线程安全
{
private:
  Singleton_hungry(){ cout<<"hungry signle "<<endl; }
  static Singleton_hungry* pSignleton;

public:
  static Singleton_hungry* getInstance() {
    return pSignleton;
  }
#if 0
  static void FreeSpace()
  {
    if(pSignleton != nullptr)
    {
      delete pSignleton;
      pSignleton = nullptr;
    }
  }
#endif


};
//程序运行之前已经创建
Singleton_hungry* Singleton_hungry::pSignleton = new Singleton_hungry;


void test()
{
  Singleton_lazy *p1 = Singleton_lazy::getInstance();

  Singleton_lazy *p2 = Singleton_lazy::getInstance();
  if(p1 == p2)
  {
    cout<<"signal lazy is sucess"<<endl;
  }
}

int main(int argc, char** argv)
{
  cout<<"main process start"<<endl;
  test();

  return 0;
}