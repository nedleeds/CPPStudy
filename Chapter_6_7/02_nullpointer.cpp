#include <iostream>
#include <cstddef>

void nullPointerStyle()
{
    std::cout << std::endl;
    // c-style
    int *null_pointer_1 = 0;
    int *null_pointer_2 = NULL;

    // modern cpp style
    int *null_pointer_3 = nullptr;
    int *null_pointer_4{nullptr};

    std::cout << "[ c-style ]"        << std::endl;
    std::cout << "- int *ptr = 0;"    << std::endl;
    std::cout << "- int *ptr = NULL;" << std::endl << std::endl;
    
    std::cout << "[ modern cpp style ]"  << std::endl;
    std::cout << "- int *ptr = nullptr;" << std::endl;
    std::cout << "- int *ptr{nullptr};"  << std::endl << std::endl;

    std::cout << "[ type of nullptr ]" << std::endl;
    std::cout << "- std::nullptr_t nptr;" << std::endl << std::endl;
}