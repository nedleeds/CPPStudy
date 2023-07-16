/**
 * @file     constructor.cpp
 * @author  DongHyeong Lee (lllee.dh@gmail.com)
 * @brief   객체 생성 시 특정 속성 및 기능을 지니도록 설정하는
 *          constructor 에 대해서 알아봅시다.
 * @date    2023-07-16
 */
#include <iostream>
#define PRINT_FUNC_NAME() std::cout << __func__ << std::endl;
using namespace std;

class MemberClass
{   // 이 방식으로 로그 찍을 때 좋을 것 같은데?
public:
    MemberClass()
    {
        PRINT_FUNC_NAME();
    }
};

class Fraction
{
private:
    MemberClass _memberClass;
    double _numerator;
    double _denominator;
    double _fracted;

public:
    Fraction(const double &in_numerator = 0, const double &in_denominator = 1)
    { // 이 부분이 생성자(constructor)이다.
      // 객체 생성 시 동작하는 부분
        cout << "Fraction constructor()" << endl;
        _numerator   = in_numerator;
        _denominator = in_denominator;
        _fracted     = in_numerator / in_denominator;
    }

    void print()
    {
        cout << _numerator   << " / ";
        cout << _denominator << " = ";
        cout << _fracted     << endl;
    }

    void frac()
    {
        _fracted = _numerator / _denominator;
    }
};

int main()
{
    Fraction one_third{1, 3}, f1;
    one_third.print();
    f1.print();

    /* !!! Caution !!!
    생성자의 parameter 가 없으면?
    즉, Fraction 클래스 안에 Fraction 에서 ()안에 아무것도 없으면
    default parameter 가 없기 때문에, 
    main 에서 클래스 생성시 인자를 넣고 생성하면 오류가 뜬다!
    */

    return 0;
}