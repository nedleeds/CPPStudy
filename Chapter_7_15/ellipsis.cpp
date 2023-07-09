#include <iostream>
#include <cstdarg> // for ellipsis

using namespace std;

double findAverage(int count, ...)
{
    // ... -> ellipsis : 생략부호
    double sum = 0;

    // visual studio 에서는 typedef char *va_list 이렇게 된다
    va_list list; 
    va_start(list, count);

    for (int arg = 0; arg < count; ++arg)
    {
        // cout << "[" << va_arg(list, int) << "]" << endl;
        sum += va_arg(list, int); // va_arg(list, int) -> list에서 int만 pop 하는 듯
    }

    va_end(list);

    return sum / count;
}

int main()
{
    cout << findAverage(1, 1, 2, 3, "Hello", 'c') << endl;
    cout << findAverage(3, 1, 2, 3) << endl;
    cout << findAverage(5, 1, 2, 3, 4, 5) << endl;
    cout << findAverage(10, 1, 2, 3, 4, 5) << endl;

    return 0;
}