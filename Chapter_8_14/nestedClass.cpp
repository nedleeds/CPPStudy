/**
 @file       nestedClass.cpp
 @author    DongHyeong Lee (lllee.dh@gmail.com)
 @date      2023-08-02
 @brief     클래스 안에 정의 될 수 있는 타입들을 봅시다
 @copyright 🌿 홍정모's 따라하면서 배우는 Cpp
*/

#include <iostream>
using namespace std;

class Fruit
{
public:
    enum class FruitType
    {
        APPLE, BANANA, CHERRY
    };
    class InnerClass {};
    struct InnerStruct {}; 
    Fruit (FruitType type) : m_type(type){}
    FruitType getType() const { return m_type; }
    
private:
    FruitType m_type;
};

int main()
{
    Fruit apple{ Fruit::FruitType::APPLE };

    if (apple.getType() == Fruit::FruitType::APPLE)
    {
        std::cout << "Apple" << std::endl;
    }


    return 0;
}