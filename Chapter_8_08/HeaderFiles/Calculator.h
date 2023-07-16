/**
 @file       Calculator.h
 @author    DongHyeong Lee (lllee.dh@gmail.com)
 @date      2023-07-16
 @brief     헤더파일과 소스파일 분리하기
            헤더파일에서는 namespace 를 전역으로 쓰면 좋지 않다. 
            어떤 모듈이든 호출 시 해당 네임스페이스가 적용되기 때문.
            그래서 소스파일에서 필요한 곳에 넣어서 사용한다.
            헤더에는 보통 적용X. class 의 선언만 남겨둔다.
 @copyright 🌿 홍정모's 따라하면서 배우는 Cpp
*/

#pragma once
#include <iostream>

class Calc
{
private:
    int _num;
public:
    Calc(const int &in_num);
    
    Calc& add(const int &in_num);
    Calc& mul(const int &in_num);
    Calc& sub(const int &in_num);
    void print();
};
