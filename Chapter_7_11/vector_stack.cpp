#include <iostream>

using namespace std;

void print_elements(const vector<int> & v)
{
    for (auto &e : v)
        cout << e << " ";
    cout << endl;
}

void example_vector()
{
    // int *v_ptr = new int[3]{1, 2, 3};

    std::vector<int> v {1, 2, 3};
    // 이렇게 초기화 하면, size: 3, capacity: 3 이야.

    print_elements(v);

    // 근데 3개를 2개로 강제로 resize 한다면?
    v.resize(2);
    cout << v.size() << " " << v.capacity() << endl;
    // size 는 2 인데, capacity 는 3 으로 찍힌다
    // 이유 : new, delete 로 메모리를 할당, 해제하면 실행 속도가 늘어난다.
    //       그래서 new, delete 를 안쓰고, 3개를 2개만 사용하도록 설정한 것.
    //       아래와 같이 pointer 로 강제 접근을 하면 3이 살아있음을 확인할 수 있다
    int *v_ptr = v.data();
    cout << v_ptr[2] << endl;

    v.reserve(10);
    print_elements(v);
    cout << v.size() << " " << v.capacity() << endl;
    // capacity 가 10으로 찍힌다


    // vector 를 stack 처럼 사용하기 : push_back / pop_back
    std::vector<int> stack;
    stack.push_back(1);
    stack.push_back(3);
    stack.push_back(5);
    stack.pop_back();
    stack.push_back(7);
    stack.push_back(9);
    print_elements(stack); // 1, 3, 7, 9
}   