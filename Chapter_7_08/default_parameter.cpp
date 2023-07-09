#include <iostream>
using namespace std;

/*
함수의 선언부와 정의부 둘 중 하나만 매개변수 초기화를 진행할 수 있다.
그 이유는, 둘 다 허용을 해주게 되면, 선언부와 정의부의 초기값이 다른 경우
어떤 값을 기준으로 초기화가 이루어져야하는지 모호해지기 때문이다.

그래서 보통 선언부에서 정의를 한다. 왜냐? 선언부를 먼저 찾기 때문
*/

void print(const int &a = 10, const int &b = 20, const int &c =30);

void print(const int &a, const int &b, const int &c)
{
    cout << a << " " << b << " " << c << endl;
}

void default_parameter_setting()
{
    print();
    print(100);
    print(100, 200);
    print(100, 200, 300);
}