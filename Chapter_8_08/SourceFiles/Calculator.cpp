/**
 @file       Calculator.cpp
 @author    DongHyeong Lee (lllee.dh@gmail.com)
 @date      2023-07-16
 @brief     헤더 파일에 선언된 함수들을 여기 소스파일에서 정의한다
 @copyright 🌿 홍정모's 따라하면서 배우는 Cpp
*/

#include "../HeaderFiles/Calculator.h"

#ifndef PRINT_FUNC_NAME
#define PRINT_FUNC_NAME() std::cout << __func__ << "() ";
#endif // PRINT_FUNC_NAME


Calc::Calc(const int &in_num)
: _num{ in_num }
{ 
    PRINT_FUNC_NAME();
    std::cout << "constructor" << std::endl;
}

Calc& Calc::add(const int &in_num)
{
    _num += in_num;
    return *this;
}

Calc& Calc::mul(const int &in_num)
{
    _num *= in_num;
    return *this;
}

Calc& Calc::sub(const int &in_num)
{
    _num -= in_num;
    return *this;
}

void Calc::print()
{
    std::cout << "num: " << _num << std::endl;
}