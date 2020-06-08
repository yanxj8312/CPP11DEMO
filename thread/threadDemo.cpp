#include <iostream>
#include <thread>
#include <chrono>

using namespace std;


//一个简单的thread demo
void func()
{
    //do task 
}

int main(int argc,char** argv)
{
    std::thread t(func);
    t.join();
    return 0;
}