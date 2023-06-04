#include <iostream>

void c11Error()
{
    /*
    cpp11 에서는 문자열 심볼릭 상수(리터럴)에 대해서
    포인터로 바로 초기화할 수 없다
    */

    // 리터럴은 메모리에 임시로 저장됐다 사라진다
    // 따라서 "JACK" 은 원래 name 에 저장되고 값이 사라져
    char name1[] = "JACK";
    char name2[] = "JACK";
    std::cout << (uintptr_t)name1 <<std::endl;
    std::cout << (uintptr_t)name2 <<std::endl;

    // 근데, 만약 포인터에 대해서 리터럴로 초기화를 한다?
    // 그러면 결국 JACK JACK 의 임시 메모리 주소가
    // ptr_name 에 저장되고, 추후 메모리 주소가 사라지면(값이 변경되면) 
    // 문제가 발생한다. 근데 이걸 c++17 에선 해결 했나봐 돌아가는 걸 보니
    // 돌아가더라도? 좋지 않은 초기화다 ~~ 이전에 버전 호환성 측면에서!
    char *ptr_name1 = "JACK JACK"; 

    // 근데 중요한건!! cpp11 에서도 동작하는 경우가 있는데
    // 그거슨 바로 ! const 를 붙여주는 경우야
    // 초기값이 변경되지 않을거라는 걸 명시적으로 표기를 하는 거니깐.
    const char *ptr_name3 = "JACK JACK JACK";
    const char *ptr_name4 = "JACK JACK JACK";
    std::cout << (uintptr_t)ptr_name3 <<std::endl;
    std::cout << (uintptr_t)ptr_name4 <<std::endl;

    // 위에서 정적 배열 이름을 다르게 해서 같은 문자열을 넣으면 주소가 다르다
    // 그치만, const char 를 쓰면, 변수명이 달라도, 같은 문자열일 경우
    // 주소값이 같게 나온다 !!!


    // cout 은 문자열이 버퍼에 들어올 것으로 판단한다.
    // 따라서 '\0'(null character)를 만나기 전까지 종료하지 않는다
    // & : 주소 연산자이므로, 끝에 null character 가 없어서
    //     출력했을 때 정상적인 출력이 나오지 않는다
    char q = 'Q';
    std::cout << q     << std::endl;
    std::cout << &q    << std::endl; 
    std::cout << *(&q) << std::endl;

}