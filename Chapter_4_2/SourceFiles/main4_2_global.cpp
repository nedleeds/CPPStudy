/*
내용
1) :: - scope resolution operator
2) static 변수
3) extern linkage - 외부 파일의 변수를 연결하기

- 전역 변수
- const int g_x; <--- 이러면 안돼 !!
- const int g_x(0); <--- 이렇게 초기화 필수
                       현재 파일 안에서만 접근 가능

- internal linkage : 다른 파일에서 해당 변수에 접근할 수 없다!
- static int g_x(1); <- 초기화 1번, 동일 메모리 주소 활용

- external linkage : 다른 파일에서 해당 변수에 접근할 수 있다!
- extern int g_y;
- extern const int g_y; <--- extern 은 가능하지만,
                             다른 곳에서 초기화를 반드시 해야한다
*/
#include <iostream>
#include "../HeaderFiles/constant.h"

int value = 123;

static int internal_global_variable = 123456;

void doSomething()
{
    static int a = 1;
    std::cout << "a: " << a++ << std::endl;
}

// forward declaration
extern void externMethod();

int main()
{
    // 1) global 변수를 local 에서 사용하기
    std::cout << value << "\t(global)" << std::endl;
    
    int value = 1;
    std::cout << value << "\t(local)" << std::endl;

    // global value 접근 시, ::(scope resolution operator) 사용
    std::cout << ::value << "\t(global)" << std::endl;

    // 2) static 변수의 동작
    // - init 은 처음 한번만 동작한다.
    // - local 범위가 종료되어도 해당 정적변수의 메모리 주소는 저장된다
    doSomething();
    doSomething();
    doSomething();
    doSomething();

    // 3) internal global 변수
    // - 외부 파일에서 현재 .cpp 의 전역변수에 접근이 불가능한 경우
    // - 현재 .cpp 의 전역변수를 internal global variable 이라고 한다
    // 위의 코드 중 , 전역에서 static 전역 변수가 된다.

    // 4) external global 변수
    // - 다른 .cpp 의 변수를 호출하거나
    // - 다른 .cpp 의 함수를 호출할 때 사용
    externMethod();

    std::cout << "==================" << std::endl;
    std::cout << "This is main.cpp " << std::endl;
    std::cout << "pi: "  << Constants::pi  << ", " << &Constants::pi << std::endl;
    std::cout << "pi1: " << Constants::pi1 << ", " << &Constants::pi1 << std::endl;

    // pi : header 파일에서 const double pi 선언만 하는 경우
    //    -> external linkage 가 활성화 되면서, 메모리를 공유하게된다
    // pi1 : header 파일에서 const double pi(3.141592) 초기화 까지 하는경우
    //    -> 소스파일에서 해당 헤더 파일을 호출할 때마다 새로운 메모리에 pi 를 초기화해서
    //       메모리 낭비가 발생할 수 있다.

    return 0;
}