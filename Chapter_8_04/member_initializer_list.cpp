/**
 @file    member_initializer_list.cpp
 @author DongHyeong Lee (lllee.dh@gmail.com)
 @brief  클래스 생성시 멤버 변수에 대해서 initializer 를 해보자
 @date   2023-07-16
*/

#include <iostream>
#define PRINT_FUNC_NAME() std::cout << "This is " << __func__ << "()" <<std::endl;
using namespace std;

class Another
{
private:
    int _i;
public:
    Another(const int &num): _i { num }{}
};

class Something
{
private:
    int     _i;
    double  _d;
    char    _c;
    int     _arr[5];
    Another _a;

public:
    // Something(){} 클래스 생성시 초기 값 세팅을 이니셜라이저로.
    Something()
    : _i{ 1 }
    , _d{ 3.14 }
    , _c{ 'x' }
    , _arr{ 1, 2, 3, 4, 5 }
    , _a(_i + 1) // initializer
    { PRINT_FUNC_NAME() }

    void print()
    {
        cout << "int: "     << _i << endl;
        cout << "double: "  << _d << endl;
        cout << "char: "    << _c << endl;
        cout << "arr: ";
        for (auto &el : _arr)
        {
            cout << el << ' ';
        }
        cout << endl;
    }
};

int main()
{
    Something s;
    s.print();

    return 0;
}