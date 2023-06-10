#include <iostream>

void doSomething(const int &a)
{
    // 포인터 변수로 파라미터를 받으면, 복사가 실행되는데 
    // const int &는 복사를 하지 않는다
    std::cout << a << std::endl;
}

void doSomething_error(const int a)
{
    // 이게 지금 c++17 버전 기준이라 그런지 동작을 하는데,
    // 원래는 이 함수가 동작을 하면 안돼
    std::cout << a << std::endl;
}

void const_reference_operator()
{
    // 기본적으로 리터럴은 임시 메모리에 저장이 돼서 추후에 해당 주소를 불러오거나 
    // 리터럴의 주소값을 포인터 변수로 저장을 할 수 없다
    // 이럴때 참조 연산자를 이용해 해당 주소값을 사용할 수 있다

    int x = 5;
    // int &ref_x = 3 + 5;  // <- 리터럴이라 참조 연산자를 사용할 수 없다
    const int &ref_x = 4 + 6; // 하지만, const int & 은 사용할 수 있다 !!

    /*
    근데, const int 와 const int & 의 차이는 뭐야..? 라고 할 수 있다.
    함수 파라미터에서 아주 유용하다!

    const int 는 리터럴을 인자로 못 받지만,
    const int & 는 리터럴을 인자로 직접 받을 수 있다고 한다.

    */


    doSomething(1);
    doSomething_error(1);
    doSomething_error(1 * 6);
}