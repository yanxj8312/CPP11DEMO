#include <iostream>

#include <string>

//简单工厂模式
using namespace std;

//抽象基类
class AbstractFruit
{
public:
  virtual void ShowName() = 0;

};

class Apple: public AbstractFruit
{
public:
  virtual void ShowName()
  {
    cout<<"apple "<<endl;
  }
};

class Pair:public AbstractFruit
{
public:
  virtual void ShowName()
  {
    cout<<"pair "<<endl;
  }
};

class Banana:public AbstractFruit
{
public:
  virtual void ShowName()
  {
    cout<<"Banana "<<endl;
  }
};

//工厂类
class FuriteFactory
{
public:
  static AbstractFruit* CreateFruit(string flag) {
    if(flag == "apple") 
    {
      return new Apple();
    } 
    else if(flag == "banana")
    {
      return new Banana();
    }
    else if(flag=="pair")
    {
      return new Pair();
    }
  }
};

void test01()
{
  FuriteFactory *factory = new FuriteFactory(); //创建工厂类
  //创建工程不需要关心只需要使用就行
  AbstractFruit * fruit = factory->CreateFruit("apple");
  fruit->ShowName();
  delete fruit;

  AbstractFruit *banana = factory->CreateFruit("banana");
  banana->ShowName();
}

int main(int argc,char ** argv)
{
  test01();
  cout<<"hello world"<<endl;

  return 0;
}