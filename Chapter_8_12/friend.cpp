/**
 @file       friend.cpp
 @author    DongHyeong Lee (lllee.dh@gmail.com)
 @date      2023-08-02
 @brief     encapsulation 을 위한 friend 키워드를 적용해 봅시다
            서로 상관 관계가 있는 class 를 friend 키워드로 적용합니다
 @copyright 🌿 홍정모's 따라하면서 배우는 Cpp
*/

#include <iostream>
using namespace std;

class A; // forward declaration

class B
{
private:
    int m_value = 2;

public:
    void doSomething(A &a); // doSomething 선언만!
};

class A
{
private:
    int m_value = 9876;

    // B 클래스의 doSomething만 A와 관련돼 있다는 걸 명시적으로 표기
    friend void B::doSomething(A &a); 
};

void B::doSomething(A &a)
{
    std::cout << a.m_value << std::endl;
}

int main()
{
    A a;
    B b;
    b.doSomething(a);

    return 0;
}