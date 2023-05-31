#include <iostream>
#include <cstdint>

int main()
{
    using namespace std;

    const int rowSize = 3;
    const int colSize = 5;

    int arr[][colSize] = {
        {1, 2, },
        {3, 4, 5, 6, 7},
        {8, 9, 10, },
    };
    
    // print Index
    for (int r = 0; r < rowSize; r++)
    {
        for (int c = 0; c < colSize; c++)
            cout << "arr[" << r << "][" << c << "]\t";
        cout << endl;
    }

    // print Value
    for (int r = 0; r < rowSize; r++)
    {
        for (int c = 0; c < colSize; c++)
            cout << arr[r][c] << '\t';
        cout << endl;
    }

    // print address
    for (int r = 0; r < rowSize; r++)
    {
        for (int c = 0; c < colSize; c++)
            cout << reinterpret_cast<uintptr_t>(&arr[r][c]) << '\t';
        cout << endl;
    }

    return 0;
}