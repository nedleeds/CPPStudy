/**
 @file       anonymous.cpp
 @author    DongHyeong Lee (lllee.dh@gmail.com)
 @date      2023-08-02
 @brief     익명 객체에 대해서 알아봅시다.
            객체변수를 만들지 않고, class object로 바로 멤버 변수를 사용해봅시다
 @copyright 🌿 홍정모's 따라하면서 배우는 Cpp
*/
#include <iostream>
using namespace std;

class Cents
{
private:
    int _cent = 0;
public:
    Cents(int cent = 0) { _cent = cent; }
    int getCent() const { return _cent; }
};

Cents add( const Cents &c1, const Cents &c2 )
{
    return Cents( c1.getCent() + c2.getCent() );
}

int main()
{
    cout << add(Cents(6), Cents(8)).getCent() << endl;
    
    return 0;
}