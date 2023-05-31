#include <iostream>
#include "../HeaderFiles/constant.h"

using namespace std;

void externMethod()
{
    std::cout << "==================" << std::endl;
    std::cout << "This is test_extern.cpp" << std::endl;
    std::cout << "pi: "  << Constants::pi  << ", " << &Constants::pi  << std::endl;
    std::cout << "pi1: " << Constants::pi1 << ", " << &Constants::pi1 << std::endl;
}
