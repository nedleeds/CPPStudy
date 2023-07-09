#include <iostream>
#include <cassert> // assert.h
#include <array>

using namespace std;

void printValue(const std::array<int, 5> &my_array, const int& idx)
{
    // assert : '디버그 모드' 에서 false 인 경우를 잡아낸다
    assert(idx >= 0);
    assert(idx < my_array.size());

    cout << my_array[idx] << endl;
}

int main()
{
    std::array<int, 5> my_array{ 1, 2, 3, 4, 5 };

    printValue(my_array, 10);

    // // 컴파일타임에서 결정되는 assert
    // // f5(debug & run) 하기 전에 바로 밑 줄로 에러 탐지
    // const int x = 10;
    // static_assert(x == 5, " x should be 5."); 

    return 0;
}