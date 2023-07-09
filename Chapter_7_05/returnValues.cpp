#include <iostream>
#include <array>
#include <tuple>

using namespace std;

int* get_int_pointer()
{
    /*
    이런 return 방식은 매우 위험하다.
    해당 함수 scope 를 벗어나면 메모리 할당이 해제된다.
    따라서 사라진 메모리에 접근하는 위험이 발생한다.
    */
    int value = 213;
    return &value;
}

int* allocateArray(int size)
{
    /*
    해당 방법은 메모리 누수를 방지하기 위한 delete
    과정이 적용되기 어렵다. 외부 함수에서 현재의 반환값을
    리턴받고 활용이 끝난 후 delete 를 해야한다.
    그렇게 되면 코드 가독성이 현저히 떨어지므로 현업에서는
    이러한 방식을 적용하지 않는다.
    */
    return new int[size];
}

int& get_element(std::array<int, 100>& my_array, int idx)
{
    // 배열과 인덱스를 받아, 해당 값의 참조값을 리턴.
    // 그럼 외부함수에서는 참조값에 값을 대입해 그 값을 변경할 수 있다.
    return my_array[idx];
}

int& get_reference_value(int x)
{
    int value = x * 2;
    return value;
}

struct S
{
    int a, b, c, d;
};

S get_struct()
{
    // 구조체 반환
    S my_struct{1, 2, 3, 4};
}

std::tuple<int, double> get_tuple()
{
    int a = 10;
    double b = 3.14;
    return std::make_tuple(a, b);
}

void returnValues()
{
    int *p_int = get_int_pointer();
    cout << p_int << " " << *p_int << endl;

    int *arr = allocateArray(1024);
    delete arr;
    
    int &value = get_reference_value(5);
    cout << value << endl;
    cout << value << endl; // 여기서 쓰레기 값 리턴.
    // 이유는 간단. 첫번째 참조 연산에서 이미 리턴된 값을 참조해서 호출했고,
    // 메모리할당을 해제한 상태였다. 근데, 재참조를 하면서 할당해제된 값을 호출한 것임

    // 많이 쓰는 접근법
    std::array<int, 100> my_array;
    my_array[30] = 10;
    get_element(my_array, 30) = 1024;
    cout << my_array[30] << endl;

    S my_struct = get_struct();
    cout << my_struct.a << " " << my_struct.b << endl;

    std::tuple<int, double>my_tp = get_tuple();
    cout << std::get<0>(my_tp) << endl;
    cout << std::get<1>(my_tp) << endl;

    // c++17
    auto[a, b] = get_tuple();
    cout << a << endl;
    cout << b << endl;
}