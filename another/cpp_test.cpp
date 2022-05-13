#include <iostream>
#include <map>
#include <string>
using std::cout;
using std::endl;
using std::string;
class A
{
public:
    int x;
    string y;
    A() : x(10) { cout << "默认构造" << endl; }
    A(const A &a) : x(a.x) { cout << "A 的拷贝构造" << endl; }
    A &operator=(const A &a)
    {
        x = a.x;
        cout << "A 的赋值运算" << endl;
        return *this;
    }
    ~A() { cout << "析构A" << endl; }
};
class B
{
public:
    A a;
    B(const A &a) : a(a) { cout << "B 的构造" << endl; }
};
class C
{
public:
    A a;
    C(const A &a)
    {
        cout << "C 的构造" << endl;
        this->a = a;
    }
};
void k1()
{
    A a;
    cout << "----------" << endl;
    B b(a);
    cout << "----------" << endl;
    C c(a);
    cout << "----------" << endl;
}
int main()
{
    int x;
    x(10);
}