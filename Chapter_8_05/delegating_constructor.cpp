/**
 @file    delegating_constructor.cpp
 @author DongHyeong Lee (lllee.dh@gmail.com)
 @brief  위임 생성자(delegating constructor)란?
         : 생성자가 다른 생성자를 사용하는 것
 @date   2023-07-16
*/

#include <iostream>
using namespace std;
#define PRINT_FUNC_NAME() cout << "This is " << __func__ << "()" << endl;

class Student
{
private:
    int     _id;
    string  _name;

public:
    Student(const int &in_id, const string &in_name)
    : _id { in_id }, _name { in_name }
    { PRINT_FUNC_NAME(); }

    Student(const int &in_id)
    : Student(in_id, "None") // 위임 생성자
    {}

    Student(const string &in_name)
    : Student(-1, in_name)   // 위임 생성자
    {}

    Student()
    : Student(0, "dhl")      // 위임 생성자
    {}

    void print()
    {
        cout << _name << "(" << _id << ")" << endl;
    }
};

int main()
{
    Student s1, s2(1, "psy");
    s1.print();
    s2.print();

    // 위임 생성자를 써서, 이름만 입력했을 때 생성되게 만들어보자
    Student s3("lsb");
    s3.print();

    // 
    Student s4(2);
    s4.print();

    return 0;
}