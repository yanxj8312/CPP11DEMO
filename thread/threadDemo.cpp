#include <iostream>
#include <thread>
#include <chrono>
#include <memory>
#include <functional>
#include <vector>

using namespace std;

//一个简单的thread demo
void func()
{
    //do task 
    printf("hello world\n");
}

//将线程保存到容器中，用来保证对象的生命周期
std::vector<std::thread> g_list;
std::vector<std::shared_ptr<std::thread>> g_list2;

void CreateThread()
{
    std::thread t(func);
    g_list.push_back(std::move(t));
    g_list2.push_back(std::make_shared<std::thread>(func));
}



void func1(int a, double b)
{

}

int main(int argc,char** argv)
{
    std::thread t(func);
    std::thread t1(std::move(t)); //当线程被移动过后，线程将不代表任何线程
    
    std::thread t2(std::bind(func1,1,2));

    CreateThread();
    for(auto &thread : g_list)
    {
        thread.join();
    }

    for(auto& thread: g_list2)
    {
        thread->join();
    }
    std::cout<<"t id is "<<t1.get_id()<<std::endl;

    //获取cpu核心数量
    std::cout<<"cpu number"<<std::thread::hardware_concurrency()<<std::endl;

    //t.join();
    t1.join();
    t2.join();
    return 0;
}