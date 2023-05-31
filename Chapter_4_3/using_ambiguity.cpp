#include <iostream>

namespace a
{
    int my_var(1);
    const int count(5);
}

namespace b
{
    int my_var(2);
}

int main()
{

    using namespace std;
    /* 
    my_var 는 namespace 마다 중복된다
    따라서 모호성을 지녀, 확실한 이름 공간을 표기해야한다
    cout << my_var << endl; // 에러 발생
    */

    // 아래와 같이 해결할 수 있다
    {
        using namespace a;
        cout << my_var << endl;
        /* 
        근데, 이름공간에서 pre-defined word 를 사용하면
        위에서 using namespace std 를 해줘서 
        이름 공간이 겹쳐서 에러를 발생시키게 된다.
        cout << count << endl; // 에러 발생
        */

        // 이렇게 using 이 겹치면 명시적으로 표기해서 해결 가능
        cout << a::count << endl;
    } 
    cout << b::my_var << endl;
    
   


    return 0;
}
