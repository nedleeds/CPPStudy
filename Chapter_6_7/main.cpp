#include <iostream>

void checkPointerSize();
void checkPointerInit();
void nullPointerStyle();
void checkPointerSizeByInt();
void ptrAddressCheck(double *ptr);

int main()
{
    checkPointerSize();
    checkPointerInit();
    nullPointerStyle();    

    double d = 123.0;
    double *ptr_d = &d;

    std::cout << "This is main"       << std::endl;
    std::cout << "value: "   << d     << std::endl;
    std::cout << "address: " << &d    << std::endl;
    std::cout << "address: " << ptr_d << std::endl << std::endl;
    ptrAddressCheck(ptr_d);

    checkPointerSizeByInt();

    return 0;
}