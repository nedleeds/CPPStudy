/**
 @file       static_value.cpp
 @author    DongHyeong Lee (lllee.dh@gmail.com)
 @date      2023-08-02
 @brief     static 변수 사용법을 제대로 파악해 봅시다
 @copyright 🌿 홍정모's 따라하면서 배우는 Cpp
*/

#include <iostream>

class Something
{
public:
    static int s_value; // 정적 변수는 클래스 안 초기화 불가능

    //아니면, static const 는 초기화와 정적변수 두 가지 모두 가능.
    static const int s_value2 = 7; // 단, 다른 곳에서 값을 못 바꾼다

    static constexpr int s_value3 = 8; // compile time 에 결정돼야하는 변수
};

int Something::s_value = 1; // 이런 식으로 초기화는 가능하다
// static 변수의 정의는 .cpp 안에 정의해야한다. header 안에 두면 컴파일 에러가 난다
// 이유: 정의는 한 곳에만 있어야한다는 중복 선언 규칙에 위배되기 때문

int main()
{
    /*
    m1 mac 에서는 static 변수를 출력하면, 동일한 주소값이 아닌 별개의 메모리 주소를 가지게 된다.
    원래는 static 을 적용하면, 정적변수가 메모리에 할당되고, 해당 메모리에 접근해
    다른 곳에서도 접근하게 된다. 따라서 동일한 주소를 공유한다
    */
    std::cout << &Something::s_value << ": " << Something::s_value << std::endl;

    Something st1;
    Something st2;

    std::cout << &st1 << ": " << st1.s_value << std::endl;
    
    st1.s_value = 2;
    
    std::cout << &st2 << ": " << st2.s_value << std::endl;
    std::cout << &st1 << ": " << st1.s_value << std::endl;

    Something::s_value = 1024;
    
    std::cout << &st2 << ": " << st2.s_value << std::endl;
    std::cout << &Something::s_value << ": " << Something::s_value << std::endl;

    return 0;
}