#include <iostream>

void ptrAddressCheck(double *ptr_double)
{
    std::cout << "This is ptrAddressCheck" << std::endl;
    std::cout << "value: "   << *ptr_double << std::endl;
    std::cout << "address: " << &ptr_double << std::endl << std::endl;
 }