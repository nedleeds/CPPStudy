#include <iostream>

void staticArrayAndPointer();
void cStyleReference(int *arr, const int arrSize);

int main()
{
    staticArrayAndPointer();

    const int ARRSIZE = 4;
    int arr[ARRSIZE]{1, 2, 3, 4};
    cStyleReference(arr, ARRSIZE);

    return 0;
}