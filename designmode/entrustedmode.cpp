#include <iostream>
#include <string>

using namespace std;
//代理模式: 提供一种方式来控制对其他对象的访问

class AbstructCommonInterface
{
public:
   virtual void run() = 0;
};

//我已经写好的系统
class MySystem : public AbstructCommonInterface
{
public:
  virtual void run() 
  {
    cout<<" run MySystem "<<endl;
  }
};
//必须要有权限验证，不是所有人都能来启动我的系统，必须提供用户名和密码
class MySystemPorxy : public AbstructCommonInterface
{
public:
  MySystemPorxy(string name, string passwd) {
    username = name;
    password = passwd;
    pSystem = new MySystem;
  }

  bool checkUsernameAndPassword()
  {
    if(username == "admin"&& password=="123456") {
      return true;
    }
    return false;
  }

  virtual void run() {
    if(checkUsernameAndPassword()) {
      cout<<"system up"<<endl;
      this->pSystem->run();
    }
    else {
      cout<<"user name or password failed"<<endl;
    }
    
  }

  ~MySystemPorxy() {
    if(pSystem !=nullptr) {
      delete pSystem;
      pSystem = nullptr;
    }
  }

private :
  MySystem *pSystem = nullptr;
  string username;
  string password;
};


int main(int argc, char** argv)
{
  MySystemPorxy *proxy = new MySystemPorxy("admin","12346");
  proxy->run();


  return 0;
}