#include <iostream>

enum Color
{
    /*
    열거형은 말그대로, 클래스인데, 필요한 변수들의 집합체라 생각하면 돼
    아래에서 마우스를 가져다 대면 알겠지만,
    위에서부터 차례대로 알아서 0,1,2,3,4 순서로 초기값이 세팅돼
    만약, 첫번째 값을 -5 로 초기화하면 -5부터 +1 씩 초기화 돼
    중간 값을 10 으로 바꾸면, 이후의 값부터 +1 씩 초기화 돼
    !!! 서로 같은 값을 초기화 하면 안돼 - 열거형이기 때문.. !!!

    많이 사용한다. 헤더파일에 따로 불리해서 호출해서 주로 사용
    */
    COLOR_BLACK = -5,
    COLOR_RED,
    COLOR_GREEN = 10,
    COLOR_BLUE,
    COLOR_SKY_BLUE,
};

int main()
{
    Color paint1(COLOR_BLACK);
    Color paint2{COLOR_RED};

    std::cout << "paint1 color: " << paint1 << std::endl;
    std::cout << "paint2 color: " << paint2 << std::endl;

    int color_num;
    std::cin >> color_num;
    Color paint3 { static_cast<Color>(color_num) };
    std::cout << "paint3 color: " << paint3 << std::endl;

    return 0;
}