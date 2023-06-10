#include <iostream>

using namespace std;

void dynamicAllocation()
{
    // 정적 할당
    // int arr[10];

    // 배열 동적 할당
    cout << "Array size : ";
    int length;
    cin >> length;

    // new 와 delete 는 한 쌍이다
    // new 해주면 delete 도 해줘야한다
    int *array = new int[length]; 
    array[0] = 1;
    array[1] = 2;

    std::cout << "Size of pointer : " << sizeof(array)          << endl;
    std::cout << *array        << " " << (uintptr_t)array       << endl;
    std::cout << *(array + 1)  << " " << (uintptr_t)(array + 1) << endl;

    delete [] array; // [] 는 배열 전체를 할당 해제 할 때 적용

    // 초기화 방법
    // uniform initialization 은 넣은 갯수만큼 해당 값 들로 초기화된다
    // !! 주의사항 : 초기값들은, 동적할당하는 배열 크기보다 작거나 같아야 안터진다 !!
    int *arr = new int[length]{999, 999, 999};
    for (int i = 0; i < length; i++)
    {
        std::cout << *(arr + i) << std::endl;
    }
    delete[] arr; // 무적권 넣어줘야해
}