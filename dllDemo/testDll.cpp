
#include "iostream"
//#include "DLLDEMO.h"
#include "windows.h"
using namespace  std;

//#pragma comment(lib,"DLLDEMO.lib")

using F_ADD = int(*)(int,int); //定义别名

int main(int argc,char ** argv)
{
    HMODULE hModule = ::LoadLibraryA("./DLLDEMO.dll"); //加载动态库
    //cout<<add(2,3)<<endl;

    if(hModule == NULL)
    {
        cout<<"load dll error"<<endl;
        return 1;
    }

    auto add = (F_ADD)::GetProcAddress(hModule,"add");
    auto sub = (F_ADD)::GetProcAddress(hModule,"sub");

    cout<<add(1,3)<<endl;
    cout<<sub(4,5)<<endl;

    return 0;
}