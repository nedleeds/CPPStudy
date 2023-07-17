/**
 @file       class_const.cpp
 @author    DongHyeong Lee (lllee.dh@gmail.com)
 @date      2023-07-16
 @brief     class 와 const 의 관계에 대해서 알아보자
 @copyright 🌿 홍정모's 따라하면서 배우는 Cpp
*/

#include <iostream>

using namespace std;

class Something
{
private:
    int _value = 0;
public:
    void setValue(int value){ _value = value; }
    int getValue() const { return _value; }
};

// int main()
// {
//     Something something; // something: "변수" = "object"
//     something.setValue(4);
//     std::cout << something.getValue() << std::endl;

//     const Something something2;
//     // something2.setValue(6);
//     // 여기서 에러가 뜬다. 왜? const 인데 값을 바꾸려고 하니깐.
    
//     // something2.getValue();
//     // 이것도 에러가 뜬다. 왜?? 이건 값을 바꾸는게 없는데??
//     // 이유: "멤버 function 역시 const 타입이어야 한다"
//     // 수정: Something class에서
//     //      int getValue() { return _value; } 를
//     //      int getValue() const { return _value; } 로
//     //      바꾸면 에러가 발생하지 않는다.
//     something2.getValue();


//     return 0;
// }