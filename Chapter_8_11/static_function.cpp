/**
 @file       static_function.cpp
 @author    DongHyeong Lee (lllee.dh@gmail.com)
 @date      2023-08-02
 @brief     static 함수에 대해서 알아봅시다
 @copyright 🌿 홍정모's 따라하면서 배우는 Cpp
*/

#include <iostream>

using namespace std;

class Something
{
public:
    // 여기 안에다 클래스를 만든다 <- inner class !!
    class _init
    {
    public:
        // constructor
        _init()
        {
            s_value = 9876;
        }
    };

private:
    int m_value = 2;

    static int s_value; // Q) static 변수를 constructor(생성자)로는 초기화가 안될까? 
                        // A) 가능해. inner class 를 사용하면.
    static _init s_initializer; // inner class 의 생성자 호출

public:
    static int getValue()
    {
        // return this->m_value; // -> static 함수는 멤버 변수에 접근 X
        // return this->s_value; // -> static 변수는 클래스 내부 선언 X -> 정적 영역에 선언됨
        return s_value;
    }

    int temp()
    {
        return this->m_value;
    }
};

int Something::s_value; // 여기서 초기화를 이렇게 정의하지않고 아래처럼 초기화가능
Something::_init Something::s_initializer;


int main()
{
    // static 함수는 당연히 외부에서 접근 가능하다
    std::cout << "Something::getValue(): " << Something::getValue() << std::endl;

    // 함수 포인터를 활용해 클래스 멤버함수를 활용해보자
    // 
    Something s1, s2;
    // int (Something::*fptr)() = &(s1::temp); // <- error
    // -> C++에서 클래스의 멤버 함수는 개별 객체 내부가 아닌 공통 메모리 위치에 저장된다. 
    //    멤버 함수는 데이터에 해당하지 않고 행동에 해당하므로 클래스의 모든 객체에 의해 공유된다. 
    //    따라서 temp()와 같은 멤버 함수의 주소를 취하면, 고려하는 객체(s1이든 s2이든)에 관계없이 동일한 주소를 얻게 된다!
    // -> 보다 정확히는, C++에서 이것은 "s1의 temp 함수가 저장된 주소"를 의미하는 것이 아니라 
    //    "s1와 함께 사용할 수 있는 temp 함수의 주소"를 의미해
    int (Something::*fptr)() = &Something::temp;

    Something st;
    std::cout << "(st.*fptr)(): " << (st.*fptr)() << std::endl;

    // static 함수는 정적 메모리에 저장되니깐 해당 주소만 따로 저장가능해
    int (*fptr2)() = &Something::getValue;
    std::cout << "fptr2(): " << fptr2() << std::endl;

    return 0;
}