#include <iostream>
#include <array>
#include <functional>
using namespace std;

void function1(const int &value)
{
    cout << "function1 : " << value << endl;
}

void function2(const int & value2)
{
    cout << "function2 : " << value2 << endl;
}

void function_pointer_ex1()
{
    // 반환 타입 : 함수 "포인터" -> 함수의 주소값
    // 매개 변수 : 인자로 들어오는 변수의 타입
    void (*p_function)(const int &) = nullptr;

    // 함수 이름 = 해당 함수의 주소 값을 저장
    p_function = function1; // 함수 포인터에 다른 함수의 function1 주소값을 대입
    p_function(10);         // 해당 함수 호출은 ()로!

    p_function = function2;
    p_function(20);
}

bool isEven(const int &var)
{
    return (var % 2 ? false : true);
}

bool isOdd(const int &var)
{
    return (var % 2 ? true : false);
}

// typedef bool (*check_even_t)(const int &);
using check_even_t = bool (*)(const int&);
void check_the_num(const array<int, 10> &arr, check_even_t check_func = isEven)
{
    for (auto x : arr)
    {
        if (check_func(x)) { cout << x << " "; }
    }
    cout << endl;
}

void check_the_num(const array<int, 10> &arr, 
                   std::function<bool(const int&)> check_func)
{
    for (auto x : arr)
    {
        if (check_func(x)) { cout << x << " "; }
    }
    cout << endl;
}

void function_pointer_ex2()
{
    array<int, 10> my_arr{0, 1, 2, 3, 4, 5, 6, 7, 8 ,9};
    check_the_num(my_arr, isEven);
    check_the_num(my_arr, isOdd);

    // c++11 부터는 functional 이라는 라이브러리가 생겼다.
    std::function<bool(const int &)> fncptr = nullptr;
    fncptr = isEven;
    check_the_num(my_arr, fncptr);

    fncptr = isOdd;
    check_the_num(my_arr, fncptr);
}