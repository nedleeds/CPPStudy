#include <iostream>

using namespace std;

void memoryLeak()
{
    // 1000 의 크기를 갖는 int 형 배열을 heap 영역에 할당
    // 해당 영역의 메모리 주소를 ptr2 에다가 저장
    int *ptr2 = new int[1000];

    // delete [] ptr2; // 메모리 할당 해제
    
    // 여기서 delete 을 안하게 되면,
    // 현재 initArray() 가 실행되면서 잡아놓은 int[1000]이
    // 계속 메모리를 잡아 먹고 있게 된다. => 메모리 누수 발생 가능성 커짐
}

void stackArea()
{
    memoryLeak(); // stack 영역에 initArray() 함수 주소가 저장된다

    // int pointer 변수 초기화
    int *ptr = nullptr;

    // heap 에다가 int * 1000000 할당 후 ptr 에 해당 주소 저장
    ptr = new int[1000000]; 
    
    // heap 할당 해제
    delete [] ptr;

    // 이후, ptr 초기화를 하지 않고, ptr 에 다른 주소값을 넣으면
    // 아직 int[1000000] 의 주소값을 갖고 있기 때문에 문제의 여지가 있다.
    // 따라서 이후 ptr 변수에 다른 주소를 대입한다면, 그 전에 초기화 해줘야한다
    ptr = nullptr;

}