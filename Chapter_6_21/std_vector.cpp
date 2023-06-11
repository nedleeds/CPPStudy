#include <iostream>

using namespace std;

void print_elements(const vector<int> &arr)
{
    for (auto el: arr)
        cout << el << ' ';
    cout << endl;
}

void std_vector()
{
    /*
    vector 는 자동으로 메모리를 해제 해준다.
    block 이 끝나면 사라지는 거지.
    그리고 vector 는 동적 할당되므로 size 를 명시적으로 정해주지 않아도 된다
    */ 

    vector<int> array;
    cout << array.size() << endl;

    vector<int> array2 = { 1, 2, 3, 4, 5 };
    cout << array2.size() << endl;

    vector<int> array3 = { 1, 2, 3 };
    cout << array3.size() << endl;

    vector<int> array4 { 1, 2, 3 };
    cout << array4.size() << endl;

    // elements 출력
    print_elements(array2);

    // resizing 도 쉽게 가능하다
    array2.resize(2);
    print_elements(array2);

}