#include <iostream>

struct Something
{
    int v1;
    float v2;
};

struct Others
{
    Something s1;
};

void reference_variable()
{
    // reference 는 별명이라 생각하면돼.
    // 그래서 본명(초기화)이 무조건 있어야돼

    using namespace std;

    int x = 5;
    int &ref = x;
    int *ptr = &x;

    cout << "x:\t"    << x    << " &x:\t"   << &x   << endl;
    cout << "&ref:\t" << ref  << " &ref:\t" << &ref << endl;
    cout << "*ptr:\t" << *ptr << " &ptr:\t" << &ptr << endl;
}

void reference_adv()
{
    Others o1;
    o1.s1.v1 = 10; // 나중에 struct 가 복잡해지면 변수가 너무 길어짐

    std::cout << o1.s1.v1 << "("<< (uintptr_t)&o1.s1.v1 << ")" << " => ";

    int &ref = o1.s1.v1; // 이렇게 참조 변수를 이용해서 관리할 수 있다
    ref = 30;   
    std::cout << ref << "("<< (uintptr_t)&ref << ")" << std::endl;
}