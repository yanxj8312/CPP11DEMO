#include <iostream>

#include<vector>
#include <list>

using namespace std;
//观察者模式 
//抽象的父类
class AbstractHero {
public:
  virtual void Uptdate() = 0;

};

//具体的观察者
class HeroA :public AbstractHero { 
public:
  HeroA()
  {
    cout<<" hero A is attack boss"<<endl;
  }
  virtual void Uptdate() 
  {
    cout<<" hero A stop"<<endl;
  }
};

class HeroB :public AbstractHero { 
public:
  HeroB()
  {
    cout<<" hero B is attack boss"<<endl;
  }
  virtual void Uptdate() 
  {
    cout<<" hero B stop"<<endl;
  }
};

class HeroC :public AbstractHero { 
public:
  HeroC()
  {
    cout<<" hero C is attack boss"<<endl;
  }
  virtual void Uptdate() 
  {
    cout<<" hero C stop"<<endl;
  }
};

//观察目标抽象
class AbstractBoss {
public:
  //添加观察者
  virtual void addHero(AbstractHero * hero) = 0;
  //删除观察者
  virtual void deleteHero(AbstractHero *hero)=0;
  //通知观察者
  virtual void notify()=0;

};

//具体的观察目标
class BossA:public AbstractBoss
{
public:
  //添加观察者
  virtual void addHero(AbstractHero * hero) 
  {
    heroList.push_back(hero);
  }
  //删除观察者
  virtual void deleteHero(AbstractHero *hero)
  {
    heroList.remove(hero);
  }
  //通知观察者
  virtual void notify()
  {
      for(auto it = heroList.begin(); it != heroList.end(); it++)
      {
        (*it)->Uptdate();
      }
  }
private:
  list<AbstractHero*> heroList;
};

void test()
{
  HeroA *heroA = new HeroA();
  HeroB* heroB = new HeroB();
  HeroC * heroC = new HeroC();

  BossA *boss = new BossA();
  boss->addHero(heroA);
  boss->addHero(heroB);
  boss->addHero(heroC);

  boss->notify();

  boss->deleteHero(heroC);

  boss->notify();
}


int main(int argc,char** argv)
{
  test();
  return 0;
}