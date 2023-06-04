#include <iostream>

struct Something
{
    int a, b, c, d;
};

void checkPointerSize()
{
    using namespace std;

    int x = 5;
    double d = 123.0;

    // address-of operator
    int *ptr_x = &x;
    auto ptr_d = &d;

    cout << sizeof(x) << endl;
    cout << sizeof(d) << endl;
    cout << sizeof(&x) << " " << sizeof(ptr_x) << endl;
    cout << sizeof(&d) << " " << sizeof(ptr_d) << endl;

    // let's check structure pointer size
    Something ss{1, 2, 3, 4};
    Something *ptr_ss = &ss;
    cout << "Struct(int * 4) size: " << sizeof(ss) << endl;
    cout << "Struct(int * 4) address size: " << sizeof(&ss) <<endl;
    cout << "pointer of Sturct(int * 4) size: " << sizeof(ptr_ss) << endl;
}

void checkPointerInit()
{
    /*
    이 부분도 Run-time 오류를 발생시켜야해
    근데, m1 mac lldb 에서는 이걸 잡아주고 있네
    엄청 위험한 경우라 고려된다. 의도에 대한 결과는 맞지만 다른 OS 를 고려하면
    심각한 위험성을 가진 코드이다.
    쓰레기 값의 주소 값을 접근하는건 위험 그 자체
    */
    std::cout << "\nLet's check pointer error.(w/o init)" << std::endl;
    int *ptr_int;

    std::cout << "Size of un-initialized pointer : " << sizeof(ptr_int) << std::endl;
}

void checkPointerSizeByInt()
{
    short short_type = 1;
    short *ptr_s = &short_type;

    std::cout << uintptr_t(ptr_s - 1) << std::endl;
    std::cout << uintptr_t(ptr_s) << std::endl;
    std::cout << uintptr_t(ptr_s + 1) << std::endl;
}