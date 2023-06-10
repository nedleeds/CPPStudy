#include <iostream>
#include <limits>
using namespace std;

void print_for_each( const int (&arr)[12])
{
    // for each 문을 써서 출력해보자
    cout << "arr address : " << arr << endl;

    for (const auto num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
}

void set_for_each( int (&arr)[12], int value )
{
    // for each 문을 써서 값을 바꿔 보자
    cout << "arr address : " << arr << endl;

    for (auto &num : arr)
    {
        num = value;
    }
}

void find_max_for_each(const int (&arr)[12])
{
    int max_num = numeric_limits<int>::lowest();

    for (const auto &num : arr)
    {
        max_num = std::max(num, max_num);
    }

    cout << "max value : " << max_num << endl;
}

void for_each()
{
    int fibonacci[]{0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};

    print_for_each(fibonacci);
    find_max_for_each(fibonacci);
    set_for_each(fibonacci, 99);
    print_for_each(fibonacci);

}