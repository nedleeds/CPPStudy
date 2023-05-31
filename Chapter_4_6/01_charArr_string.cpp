#include <iostream>
#include <typeinfo>

void caseError1();
void caseError2();
void caseResolved1();
void caseResolved2();

int main()
{

    const char my_str[] = "Hello world!"; 
    const std::string hello{"Hello world!"};

    std::cout << my_str << "("<< typeid(my_str).name() << ")"<< std::endl;
    std::cout << hello  << "("<< typeid(hello).name() << ")"<< std::endl;

    // caseError1();
    // caseError2();
    // caseResolved1();
    caseResolved2();

    // string 더하기(append)
    std::string a("hi, ");
    std::string b("I'm lee.");
    std::string c = a + b;
    c += " I'm good.";

    std::cout << c << "(" <<c.length() << ")"<< std::endl;


    return 0;
}