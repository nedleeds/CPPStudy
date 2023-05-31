#include <iostream>
#include "../HeaderFiles/01_struct.h"

int main()
{
    Person me{"dhl", 31, 177.5, 70.0};
    Person me_copy{me}; 
    // -> 가능은 하지만, 구조체가 복잡해지면
    //    사용하지 않는 것을 추천한다

    me.print();
    me_copy.print();

    Family my_family;
    my_family.print();   

    std::cout << sizeof(Employee) << std::endl;

    return 0;
}