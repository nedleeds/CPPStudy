#include <iostream>

void pointerAndConst()
{
    // 1) 상수변수 와 상수 포인터
    //    상수 변수 -> 변하지 않는 값
    //    임시 pointer 로 해당 변수의 주소를 가르키게 하면 에러 발생
    //    pointer 역시 const int * 처럼 해줘야 에러가 발생하지 않는다
    const int value = 5; 
    // int *ptr_v = &value; // <- error 발생
    const int *ptr_v = &value;

    //대신 해당 포인터로 값 변경은 불가능하다
    // *ptr_v = 10; // <- error 발생

    // 2) 변수 와 상수 포인터
    //    일반 변수는 값을 바꿀 수 있다, 근데 상수 포인터를 해당 변수를 가르키게
    //    하고, 포인터로 값을 바꾸는 건 불가능. 그냥 변수를 직접 변경하는 건 가능
    int value_2 = 12;
    const int *ptr_v2 = &value_2;
    // *ptr_v = 4; // <- error 발생
    value_2 = 13;
    std::cout << *ptr_v2 << std::endl;

    // 3) 핵심
    //    상수 포인터 : 포인터가 가르키고 있는 변수의 값을 바꾸지 않겠다이다
    //               const int * ptr; 에대해서 ptr 의 주소값은 변경가능하다
    //    쉽게, const int* 는 (const int)* 이지, const (int *) 가 아니다
    ptr_v2 = &value;

    // 4) 그러면 pointer 를 상수화 하고 싶으면 어떻게 해야할까?
    int value_3 = 10;
    int value_4 = 9;
    int * const ptr_v3 = &value_3;
    // ptr_v3 = &value_4; // <- error 발생
    value_3 = 1; // 가르키고 있는 변수 값 자체를 바꾸는 건 가능

    // 5) 값도 바꾸지말고, 주소값도 바꾸지마 !! 는 어떻게 하면될까?
    //    변수, 포인터 둘다 const 붙여
    const int value_5 = 99;
    const int *const ptr_v5 = &value_5;
}