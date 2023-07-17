/**
 @file       copy_constructor.cpp
 @author    DongHyeong Lee (lllee.dh@gmail.com)
 @date      2023-07-17
 @brief     앞서 배웠던, 인자 값에 참조 연산자(&)를 쓰지 않으면
            파라미터로 전달된 값을 메모리에 새로 복사해서 씀을 확인하자.
 @copyright 🌿 홍정모's 따라하면서 배우는 Cpp
*/

#include <iostream>

using namespace std;

class Something
{
private:
    int _value;
public:
    Something(const int &in_num): _value(in_num)
    {
        cout << "Constructor" << endl;
    }

    // Something(const Something& st_in)
    // {   // This is Copy Constructor
    //     _value = st_in._value;
    //     cout << "Copy Constructor" << endl;
    // }

    int getValue() const
    {
        return _value;
    }
};

void print_arg_passed_by_copy(Something s){
    // 여기서 Something s 이기 때문에, main 의 s 주소와 다르다.
    // 근데!? constructor 는 한번만 동작한다. 왤까?
    // 복사를 하는 경우, 복사용 'copy constructor'가 동작해서다.
    // Something 클래스의 copy constructor를 주석해제하고 실행해보자.
    cout << "["<< &s << "] " << s.getValue() << endl;
}

int main()
{
    Something s{ 1.0 };

    cout << "[" << &s << "] " << s.getValue() << endl;
    print_arg_passed_by_copy(s);

    return 0;
}