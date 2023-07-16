/**
 @file       destructor.cpp
 @author    DongHyeong Lee (lllee.dh@gmail.com)
 @date      2023-07-16
 @brief     생성자와 소멸자의 동작 순서 파악
 @copyright 🌿 홍정모's 따라하면서 배우는 Cpp
*/

#include <iostream>
using namespace std;

class Something
{
private:
    int _arg;

public:
    Something(const int &idx)
    : _arg(idx)
    {
        cout << "[" << _arg << "] This is constructor." << endl;
    }

    Something()
    : Something(-1)
    {}
    
    ~Something()
    {
        cout << "[" << _arg << "] This is destructor." << endl;
    }
};

class IntArray
{
private:
    int *_arr = nullptr;
    int _length = 0;

public:
    IntArray(const int &in_length)
    { 
        _length = in_length;
        _arr    = new int[in_length]; // class 생성 시 동적할당
    }

    ~IntArray() 
    {
        /*
            nullptr 이 아닌 경우 class 소멸 시 동적해제.
            해주지 않으면 memory leak 발생
        */
       
        if (_arr != nullptr)
            delete [] _arr;
    }
};

int main()
{
    Something s2(1), s3(2);

    /*
    [보충] 소멸자는 instance 가 메모리에서 해제될 때 내부에서 자동으로 
    호출됩니다. 동적할당으로 만들어진 경우에는 영역을 벗어나도 자동으로 
    메모리 해제되지 않기 때문에 delete 로 메모리를 해제할 때에만 소멸자가 
    호출됩니다. 소멸자를 프로그래머가 직접 호출하는 것은 대부분의 경우 
    권장하지 않습니다.
    */ 
    Something *s1 = new Something(0);
    delete s1; // 소멸자 직접 호출 시, 먼저 실행된다

    int cnt { 9999999 };
    while(cnt--)
    {
        IntArray(100000);
        cout << cnt << endl;  
    }

    return 0;
}