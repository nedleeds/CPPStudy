#include <iostream>
#include <typeinfo>

int main()
{
    using namespace std;

    // [ implicit type casting ]
    // 'numeric conversion'
    //     1) 큰 녀석을 -> 작은 공간으로 (문제 발생)
    //        ex: double -> int
    int a = 123.0; 
    cout << typeid(123.0).name() << " -> ";
    cout << typeid(a).name() << endl;
    //       truncation 경우 (vscode는 overflow 처럼 된다)
    char b = 130; // char : -128 ~ 127 까지 표현
    cout << static_cast<int>(b) << endl; // -126

    //     2) 작은 녀석을 -> 큰 공간 (문제 없어)
    //        ex: float(4byte) -> double(8byte)
    double f = 123.4f;
    cout << typeid(123.4f).name() << " -> ";
    cout << typeid(f).name() << endl;

    // unsigned 타입 연산
    // unsigned - int       : unsigned
    // unsigned - unsigned  : unsigned
    // int      - int       : int
    cout << 5u - 10  << endl; 
    cout << 5u - 10u << endl; 
    cout << 5  - 10  << endl; // 위와 같을거라 생각했는데 아니다!
    // !!! 형 변환도 우선순위가 존재한다 !!!
    // 1) int(4byte) 보다 작은 사이즈의 타입은 무조건 int 로 바뀐다
    // 2) 순위
    //    int < unsigned int < long < unsigned long
    //    < long long < unsigned long long < float < double
    //    < long double

    // explicit type casting
    // 1) cpp style
    int a = int(3.14592);
    // 2) c style
    int b = (int)3.142592;
    // 3) recent style
    int a = static_cast<int>(3.141592);

    return 0;
}

