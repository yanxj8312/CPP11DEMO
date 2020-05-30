#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

struct Complicated
{
    int year;
    double contry;
    std::string name;

    //构造函数
    Complicated(int a,double b,string c):year(a),contry(b),name(c)
    {
        cout<<"is constucted"<<endl;
    }

    //移动构造
    Complicated(const Complicated&other):year(other.year),
    contry(other.contry),name(std::move(other.name))
    {
        cout<<"is moved "<<endl;
    }
};

int main(int argc, char** argv)
{
    std::map<int ,Complicated> m;
    int anInt = 4;
    double aDouble = 5.0;
    std::string astring = "C++";

    cout<<"--insert--"<<endl;
    m.insert(std::make_pair(4,Complicated(anInt,aDouble,astring)));

    cout<<"--emplace--"<<endl;
    m.emplace(4,Complicated(anInt,aDouble,astring));

    cout<<"--emplace_back--"<<endl;
    vector<Complicated> v;
    v.emplace_back(anInt,aDouble,astring);

    cout<<"--push_back--"<<endl;
    v.push_back(Complicated(anInt,aDouble,astring));


    return 0;
}