#include <iostream>

void memoryLeak()
{
    /*
    pointer 를 할당하고, delete 를 안하면 메모리 누수가 발생한다
    따라서, delete 로 할당해제를 해줘야한다 !!

    그치만, 메모리에 대한 권한을 받으려면, 프로세스가 OS 에 요청해야한다
    즉, cpu 처리 level -> OS 처리 level 까지 가면서 처리속도가 느려진다
    */
    while (1)
    {
        int *ptr = new int;
        std::cout << ptr << std::endl;
        
        delete ptr;
    }
}