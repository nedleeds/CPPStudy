/**
 @file       chaining_member_function.cpp
 @author    DongHyeong Lee (lllee.dh@gmail.com)
 @date      2023-07-16
 @brief     this 포인터와 연쇄 호출에 대해서 알아보자
 @copyright 🌿 홍정모's 따라하면서 배우는 Cpp
*/

#include <iostream>

using namespace std;

class Simple
{   // this 개념

private:
    int _id;

public:
    Simple(const int &in_id)
    { 
        setId(in_id); // this->setId(in_id); 와 동일
    }

    void setId(const int &in_id){ _id = in_id; }
    int  getId(){ return _id; }
};

class Calc
{   // chaining member functions
private:
    int _num;

public:
    Calc (const int &in_num = 0)
    : _num {in_num}
    { cout << "Calculator has been created." << endl;}

    Calc& add(const int &in_num)
    {
        _num += in_num;
        return *this; // 현재 클래스 주소를 반환
    }

    Calc& sub(const int &in_num)
    {
        _num -= in_num;
        return *this;
    }

    Calc& mul(const int &in_num)
    {
        _num *= in_num;
        return *this;
    }
    
    void print()
    {
        cout << "Ans: " << _num << endl;
    }
};

int main()
{
    // this 개념
    Simple s1(0), s2(1);

    cout << "s1 id: " << s1.getId() << endl;
    cout << "s2 id: " << s2.getId() << endl;

    s1.setId(99);
    s2.setId(77);
    cout << "s1 id: " << s1.getId() << endl;
    cout << "s2 id: " << s2.getId() << endl;

    // chaining member functions
    Calc c(10);
    
    // 이렇게 하던 것을
    c.add(10);
    c.mul(2);
    c.sub(19);
    c.print();

    // 이렇게 할 수 있다. by 클래스 주소 반환
    Calc c2(10);
    c2.add(10).mul(2).sub(19).print();

    return 0;
}