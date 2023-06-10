#include <iostream>

void staticAllocation()
{
    /*
    정적 할당 -> stack 영역에 할당된다 -> stack 은 용량이 작다
    동적 할당 -> heap  영역에 할당된다 -> heap  은 용량이 크다
    */
    int arr[10000000];
}

void dynamicAllocation()
{
    /*
    [정적할당]
    int var; 
    var = 7;
    */

    // 동적할당 + 대입연산
    int *ptr_1 = new int;
    *ptr_1 = 7;

    // 동적할당 + 초기화()
    int *ptr_2 = new int (7);
    int *ptr_3 = new int {7};

    std::cout << *ptr_1 << " ";
    std::cout << *ptr_2 << " ";
    std::cout << *ptr_3 << std::endl;

    // 할당된 메모리 해제
    // delete 로 운영체제가 나중에 알아서 메모리 해제하기 전에
    // 내가 직접 메모리 해제하는 것
    delete ptr_1;
    std::cout << "After delete mermory" << std::endl;
    std::cout << *ptr_1 << std::endl;
    
    // 출력해보면 알겠지만, delete 를 하게 되면 쓰레기값이 출력이 된다
    // 그래서 보통 delete 뒤에 nullptr 로 초기화 하는 코드가 붙는다
    delete ptr_2;
    ptr_2 = nullptr;
    if (ptr_2 != nullptr)
    {
        std::cout << *ptr_2 << std::endl;
    }
    else
    {
        std::cout << "ptr_2 is nullptr." << std::endl;
    }

    // delete 와 null 할당 시 주의해야할 점
    int *ptr_4 = ptr_3;
    delete ptr_3;
    ptr_3 = nullptr;
    // Q. 위의 코드에서 문제가 발생할 수 있는 부분은 ??
    // A) ptr_4 가 ptr_3 를 가르키고, ptr_3 를 nullptr 로
    //    null 값을 가르키도록 했는데, ptr_4 를 참조하면 터지게 된다
    // 따라서!!
    ptr_4 = nullptr; 
    // 위와 같이 ptr_3 를 가르키는 ptr_4 도 nullptr 로 초기화 해줘야 한다
    // 요즘은 스마트 포인터가 알아서 해준다고 한다
}

