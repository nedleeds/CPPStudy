#include <iostream>

int main()
{
    /*
    scoped enum : 영역 제한형 열거형 (열거형 클래스)
    enum class : 말 그대로, 열거형을 클래스화 한 것
    왜?
    enum Fruit
    {
        BANNANA
        APPLE
    }
    enum Color
    {
        YELLOW
        RED
    }
    디폴트 조건에 의하면 BANNANA == YELLOW 이렇게 된다.
    말이 안되는거지 -> 그래서 영역을 설정하는 것. 다음과 같이.
    */    
    enum class Color
    {
        YELLOW,
        RED,
    };

    enum class Fruit
    {
        BANNANA,
        APPLE,
    };

    Color color1 = Color::YELLOW;
    Fruit color2 = Fruit::BANNANA;

    // 타입이 아얘 다른 것으로 인식되어 비교가 안된다
    // if(color1 == color2)
    // {
    //     std::cout << "same color" << endl;
    // }

    // 강제로 비교하는 경우
    if (static_cast<int>(color1) == static_cast<int>(color2))
    {
        std::cout << "same color value" << std::endl;
    }

    return 0;
}