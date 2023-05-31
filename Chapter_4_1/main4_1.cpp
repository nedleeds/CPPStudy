/*
함수명, parameter 모두 같은 경우
중복되었다는 오류가 발생한다.
그럴때, 서로 다른 이름 공간으로 오류를 해결할 수 있다
*/

#include <iostream>

namespace work1
{
    void doSomething()
    {
        int a = 1;
        std::cout << "a: " << a << std::endl;
    }
}

namespace work2
{
    void doSomething()
    {
        int a = 3;
        std::cout << "a: " << a << std::endl;
    }   
}

// namespace 안에 namespace 를 중첩해서 만드는 것도 가능하다
// 하지만, 3중까지 들어가는 경우는 드물다.
// 홍정모 선생님은 1개까지 주로 사용한다고 한다.
namespace work2
{
    namespace work3
    {
        namespace work4
        {
            void doSomething()
            {
                int a = 4;
                std::cout << "a: " << a << std::endl;
            }   
        }
    }
}

// c++17 부터는 위의 코드를 가독성과 관련해 아래와 같이 적용 가능하다
namespace work5::work6::work7
{
    void doSomething()
    {
        int a = 5;
        std::cout << "a: " << a << std::endl;
    }  
} 


int main()
{
    work1::doSomething();
    work2::doSomething();
    work2::work3::work4::doSomething();
    work5::work6::work7::doSomething();

    return 0;
}