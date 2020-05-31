#ifndef DLLDEMO_H
#define DLLDEMO_H


#define DEMO_DLL
#ifdef DEMO_DLL
#define DLL_API __declspec(dllexport) //导出
#else
#define DLL_API __declspec(dllimport) //导入
#endif //DEMO_DLL


#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

int DLL_API add(int a,int b);

int DLL_API sub(int a,int b);



#ifdef __cplusplus
}
#endif //__cplusplus


#endif // !DLLDEMO_H

//如何编译动态库？ 可以使用cl.exe来编译
//编译指令 cl /LDd *.cpp
//需要注意动态库x86和x64的区别，以及debug和release的区别
//dll 劫持 使用同名dll和同名函数，程序优先查找当前目录下的dll，所以会调用我们的dll接口，我们再转调用用户需要使用的dll接口，就可以完成劫持
