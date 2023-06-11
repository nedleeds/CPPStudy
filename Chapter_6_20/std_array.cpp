#include <iostream>
#include <algorithm>
using namespace std;

void print_length(const array<int, 5> &arr)
{
    /*
    size 라는 메서드도 있다.
    +) parameter 에 array<int, 5> 만하면, 복사가 되기 때문에 & 를 사용한다
    */
    cout << arr.size() << endl;
}

void print_element(const array<int, 5> &arr)
{
    for (auto el: arr)
        cout << el << ' ';
    cout << endl;
}

void sort_elements(array<int, 5> &arr)
{
    // algorithm 헤더에 sort 동작
    sort(arr.begin(), arr.end());
}

void std_array()
{
    // int array[] = { 1, 2, 3, 4, 5 };

    array<int, 5> my_arr = { 1, 2, 3, 4, 5 };
    my_arr = { 0, 1, 2, 3, 4 };
    my_arr = { 0, 1, 2, };

    /*
    1. 예외처리
       일반적으로 선언된 배열 크기를 초과하는 인덱스를 입력하면,
       해당 위치로 접근을 일단하고, 에러가 뜬다.
       근데 at을 사용하면 컴파일 단계에서 잡아낸다
       즉, at은 자동 예외처리 적용된다. 그치만 느리기때문에
       속도가 중요한 작업에서는 인덱스를 그대로 쓴다
    */
    // cout << my_arr[10] << endl;
    // cout << my_arr.at(10) << endl;

    print_length(my_arr);
    print_element(my_arr);
    sort_elements(my_arr);
    print_element(my_arr);
}