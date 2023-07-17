/**
 @file       const_overriding.cpp
 @author    DongHyeong Lee (lllee.dh@gmail.com)
 @date      2023-07-17
 @brief     클래스 내 const/non-const method 를 정의해봅시다
 @copyright 🌿 홍정모's 따라하면서 배우는 Cpp
*/

#include <iostream>

using namespace std;

class Something
{
public:
    string _value = "default";

    Something(const string &in_str) : _value { in_str }
    {
        cout << "Constructor" << endl;
    }

    const string& getValue() const
    {
        cout << "const version" << endl;
        return _value;
    }

    string& getValue()
    {
        cout << "non-const version" << endl;
        return _value;
    }

};

int main()
{
    Something s1{"A"};
    // s1.getValue() 하면 return 이 string& 라서, 
    // s1.getValue() = _value = "Z"; 가 된다.
    // 따라서, non-const 인 만큼 class 의 멤버 변수값이 바뀌게 된다.
    s1.getValue() = "Z"; 
    cout << s1.getValue() << endl;

    const Something s2{"B"};
    s2.getValue();
    cout << s2.getValue() << endl;


    return 0;
}