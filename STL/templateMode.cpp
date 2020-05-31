#include <iostream>
#include<vector>

using namespace std;

//模板方法模式，定义一套抽象算法，让子类继承实现，从而实现抽象算法的不同实现

class DrinkTemplate {

public:
  virtual void BolidWater() = 0;
  virtual void Brew() =0;
  virtual void PourInCup() = 0;
  virtual void AddSomth() = 0;

  //模板方法
  void Make()
  {
    this->BolidWater();
    this->Brew();
    this->PourInCup();
    this->AddSomth();
  }

};

class MakeCoffe : public DrinkTemplate
{
public:
  virtual void BolidWater() 
  {
    cout<<"bolid water"<<endl;
  }
  virtual void Brew() 
  {
    cout<<"Brew coffe"<<endl;
  }
  virtual void PourInCup() 
  {
    cout<<"pourIn cup"<<endl;
  }
  virtual void AddSomth() 
  {
    cout<<"add melik"<<endl;
  }
};

class Tea : public DrinkTemplate
{
public:
  virtual void BolidWater() 
  {
    cout<<"bolid water"<<endl;
  }
  virtual void Brew() 
  {
    cout<<"Brew tea"<<endl;
  }
  virtual void PourInCup() 
  {
    cout<<"pourIn cup"<<endl;
  }
  virtual void AddSomth() 
  {
    cout<<"add suger"<<endl;
  }
};


int main(int argc,char** argv)
{
  Tea *  tea = new Tea();
  tea->Make();

  MakeCoffe *coffee = new MakeCoffe();
  coffee->Make();

  return 0;
}