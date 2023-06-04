#include <iostream>

void passArrayCheckSize(int arr []);
void printArray(int *arr, const int arrSize);

void staticArrayAndPointer()
{
    /*
    정적 배열은 초기화 시 크기가 고정
    -> 그치만, 배열 이름은 결국 첫번째 요소의 주소값을 저장하고 있다
    그렇다면, pointer 와의 차이는 무엇일까?
    int *ptr = arr; 로
    동일한 주소값을 저장하는데 무슨 차이란 말일까??

    -> sizeof(arr) 은 배열 요소 타입의 크기 * 배열의 크기
    -> sizeof(ptr) 은 포인터 크기 (시스템 주소 크기)
    
    이렇게 차이가 나게 된다
    즉, int arr[5] => int * 5 => 4 * 5 => 20 Bytes
    int *ptr = arr => pointer size => 4 Bytes (m1 mac: 8 Bytes)
    */
    using namespace std;

    // static array - fixed sized array
    int arr[5]{9, 12, 34, 5, 1};
    int *ptr = arr;

    cout << "sizeof(arr): " << sizeof(arr) << endl;
    cout << "int *ptr = arr; " << endl;
    cout << "sizeof(ptr): " << sizeof(ptr) << endl;

    passArrayCheckSize(arr);
}

void passArrayCheckSize(int arr [])
{
    /*
    배열의 이름을 argument 로 넘겨 받아서, 요소타입크기 * 요소수
    이렇게 나올 것 같지만, 실제론 pointer 로 인식되기 때문에
    시스템 주소 사이즈로 나온다(window: 4, m1 mac: 8)
    */
   
    std::cout << "[ passArrayCheckSize ]" << std::endl;
    std::cout << "size: " << sizeof(arr) << std::endl;
}

void cStyleReference(int *arr, const int arrSize)
{
    /*
    c 언어에서는 참조 연산을 포인터로 진행한다.
    그치만 modern cpp 에서는 아얘 cpp 참조연산자(&)를 활용해서 진행한다
    */
   printArray(arr, arrSize);
   arr[0] = -1;
   printArray(arr, arrSize);
}

void printArray(int *arr, const int arrSize)
{
    using namespace std;
    for (int i = 0; i < arrSize; i++)
    {
        cout << *(arr++) << ' ';
    }
    cout << endl;
}