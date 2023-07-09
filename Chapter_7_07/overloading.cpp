#include <iostream>
using namespace std;

void print(const unsigned int &value)
{
    cout << value << endl;
}

void print(const float &value)
{
    cout << value << endl;
}

void function_overloading()
{
    // print('a')   // 오버로딩 시 매개변수가 char   가 없어서 ambiguous !
    // print(1)     // 오버로딩 시 매개변수가 int    가 없어서 ambiguous !
    // print(3.14)  // 오버로딩 시 매개변수가 double 이 없어서 ambiguous !

    print(1u);
    print(3.14f);
}