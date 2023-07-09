#include <iostream>

using namespace std;

void addOne(int &y)
{
    y = y + 1;
}

void getSinCos(const double degree, double &sin_out, double &cos_out)
{
    // static : 한번 초기화 및 재사용 가능
    // 변하지 않는 값은 const 로 고정 시키는게 안전하다
    /*
    static const double pi = 3.141592; 
    const double radians = degree * pi / 180.0;

    위의 구문은, static const 는 한번만 초기화 되고 이후에는 고정이기 때문에
    여기서 나눗셈을 하면 딱 한번만 하게 된다!! 따라서 훨씬 효율이 높아지게돼.
    반면, const double 구문은 매 함수 시에 실행이 되기 때문에 연산을 줄이는게 좋아
    */
    static const double pi = 3.141592 / 180.0; 
    const double radians = degree * pi;

    cout << radians << endl;

    sin_out = std::sin(radians);
    cos_out = std::cos(radians);
}

void printSinCos(const double &degree, const double &sin, const double &cos)
{
    cout << "sin(" << degree << "): " << sin << ' ';
    cout << "cos(" << degree << "): " << cos << endl;
}

void foo(const int &x)
{
    // 파라미터에 const 가 아닌, int & 를 적용하면
    // 리터럴의 주소를 받아올 수 없어서 에러가 뜬다
    // 이럴 땐 const 를 붙이면 동작한다
    cout << x << endl;
}



void callByReference()
{
    /*
    Hong 이 가장 많이 사용하고 오픈소스에도 매우 빈번하게 등장
    */
    int x = 5;

    cout << x << " " << &x << endl;
    
    addOne(x);

    cout << x << " " << &x << endl;

    /*
    함수 리턴 값이 많을 때, 해당 값들을 참조 연산자로
    arguments 로 전달해 함수 내부에서 처리하는 방식
    -> 해당 기법은 정말 많이 사용한다고 한다
    -> get 이라고 해서 꼭 리턴값을 해 줄 필요가 없다..!
    */
    double sin(0.0);
    double cos(0.0);
    double degree = 30.0;

    getSinCos(degree, sin, cos);
    printSinCos(degree, sin, cos);

    degree = 45.0;
    getSinCos(degree, sin, cos);
    printSinCos(degree, sin, cos);

    degree = 60.0;
    getSinCos(degree, sin, cos);
    printSinCos(degree, sin, cos);

    foo(7);
}

void printPointerRef(int* &pInt)
{
    cout << "pInt: " << pInt << " " << "*pInt: " << *pInt << endl;
    cout << "pInt + 1: ";
    *pInt += 1;
}

void pointerReference()
{
    cout << "This is pointer Reference example." << endl;
    int x = 100;
    int *pInt = &x;

    cout << "&x  : " << &x << endl;
    printPointerRef(pInt);
    cout << x << endl;
}