#include <iostream>

//抽象工厂模式
using namespace std;

//抽象苹果
class AbstractApple
{
public:
  virtual void ShowName()=0;
};

class ChinaApple : public AbstractApple
{
public:
  virtual void ShowName()
  {
    cout<<"china apple"<<endl;
  }
};

class USApple : public AbstractApple
{
public:
  virtual void ShowName()
  {
    cout<<"USA apple"<<endl;
  }
};


class JapanApple : public AbstractApple
{
public:
  virtual void ShowName()
  {
    cout<<"japan apple"<<endl;
  }
};


class AbstractBanana
{
public:
  virtual void ShowName()=0;
};

class ChinaBanana : public AbstractBanana
{
public:
  virtual void ShowName()
  {
    cout<<"china banana"<<endl;
  }
};

class USBanana : public AbstractBanana
{
public:
  virtual void ShowName()
  {
    cout<<"USA banana"<<endl;
  }
};

class JapanBanana : public AbstractBanana
{
public:
  virtual void ShowName()
  {
    cout<<"japan banana"<<endl;
  }
};


class AbstractPear
{
public:
  virtual void ShowName()=0;
};

class ChinaPear : public AbstractPear
{
public:
  virtual void ShowName()
  {
    cout<<"china pear"<<endl;
  }
};


class USPear : public AbstractPear
{
public:
  virtual void ShowName()
  {
    cout<<"USA pear"<<endl;
  }
};


class JapanPear : public AbstractPear
{
public:
  virtual void ShowName()
  {
    cout<<"japan pear"<<endl;
  }
};

//抽象工厂 针对产品族 新增水果需要修改工厂代码，新增工厂不需要修改代码
class AbstractFactory
{
public:
  virtual AbstractApple* CreateApple() = 0;
  virtual AbstractBanana* CreateBanana()=0;
  virtual AbstractPear* CreatePear()=0;
};

class ChinaFactory:public AbstractFactory
{
public:
   virtual AbstractApple* CreateApple()
   {
     return new ChinaApple();
   }
  virtual AbstractBanana* CreateBanana()
  {
    return new ChinaBanana();
  }
  virtual AbstractPear* CreatePear()
  {
    return new ChinaPear();
  }
};

class USAFactory:public AbstractFactory
{
public:
   virtual AbstractApple* CreateApple()
   {
     return new USApple();
   }
  virtual AbstractBanana* CreateBanana()
  {
    return new USBanana();
  }
  virtual AbstractPear* CreatePear()
  {
    return new USPear();
  }
};

class JapanFactory:public AbstractFactory
{
public:
   virtual AbstractApple* CreateApple()
   {
     return new JapanApple();
   }
  virtual AbstractBanana* CreateBanana()
  {
    return new JapanBanana();
  }
  virtual AbstractPear* CreatePear()
  {
    return new JapanPear();
  }
};

int test()
{
  AbstractFactory *factory = new ChinaFactory;
  AbstractApple* apple = factory->CreateApple();
  AbstractBanana* banana = factory->CreateBanana();
  apple->ShowName();
  banana->ShowName();


}

int main(int argc ,char** argv)
{
  test();
  return 0;
}