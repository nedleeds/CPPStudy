#include <iostream>
#include <iomanip>
using namespace std;

void void_pointer()
{
    // 보이드 포인터 = generic pointer (포괄적 포인터)
    int  i = 5;
    float f = 3.0f;
    char c = 'a';

    void *ptr = nullptr;

    // void 포인터이므로, 타입에 상관없이 주소값을 다 받는다
    ptr = &i;
    ptr = &f;

    // 편하지만, 나중에 돼서 해당 포인터가 가르키는 변수의
    // 타입이 무엇인지 모르는 경우가 발생한다
    // 그렇기에 포인터 연산 또한 할 수 없다 ! 크기를 모르니깐!
    // cout << ptr + 1 << endl; // <- 에러발생 !
    // cout << *ptr    << endl; // <- 에러발생 !
    
    // 해결방법 - 타입 캐스팅을 해줘야한다
    cout << fixed << setprecision(1) << *static_cast<float*>(ptr) << endl;

    // 근데 이렇게까지 해서 void 포인터를 써야해?? ㅇㅇ 나중에 쓰게 돼

}