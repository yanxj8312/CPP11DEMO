#include <iostream>
#include <vector>

using namespace std;

struct A
{
    int x;
    double y;
    A(int a, double b):x(a),y(b){}
};


int main(int argc,char ** argv)
{
    vector<A> v;
    v.emplace_back(1,2);
    cout<<v.size()<<endl;
    return 0;
}