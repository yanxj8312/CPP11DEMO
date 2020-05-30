#include <iostream>

#include <string>

//工厂方法模式， 将工厂抽象并为每个类实现一个工厂方法
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
class AbstreactFactory
{
public:
 virtual AbstractFruit* CreateFruit(string flag) =0;
};

class AppleFactory : public AbstreactFactory
{
public:
  virtual AbstractFruit* CreateFruit(string flag)
  {
    return new Apple();
  }
};

class PairFactory : public AbstreactFactory
{
public:
  virtual AbstractFruit* CreateFruit(string flag)
  {
    return new Pair();
  }
};


class BananaFactory : public AbstreactFactory
{
public:
  virtual AbstractFruit* CreateFruit(string flag)
  {
    return new Banana();
  }
};

void test01()
{
  AbstreactFactory *factory = new AppleFactory;
  AbstractFruit *fruit = factory->CreateFruit("apple");
  fruit->ShowName();
  delete factory;
  delete fruit;
}

int main(int argc,char ** argv)
{
  test01();
  cout<<"hello world"<<endl;

  return 0;
}