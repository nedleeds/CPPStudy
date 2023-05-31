#include <iostream>

#ifndef MYSTRUCT_H
#define MYSTRUCT_H
struct Person
{
    std::string name;
    int age;
    double height;
    double weight;

    void print()
    {
        std::cout << "name:\t"   << name   << std::endl;
        std::cout << "age:\t"    << age    << std::endl;
        std::cout << "height:\t" << height << std::endl;
        std::cout << "weight:\t" << weight << std::endl;
    }
};

struct Family
{
    Person me{"dhl", 31, 177.5, 70.0};
    Person bro{"sbl", 27, 179.0, 80.0};
    Person mom{"smj", 57, 164.5, 60.0};
    Person dad{"ycl", 61, 174.5, 74.0};

    void print()
    {
        std::cout << "\nFamily Info" << std::endl;
        me.print();
        bro.print();
        mom.print();
        dad.print();
    }
};

struct Employee // 2+(+2)+4+8 = 16 byte -> padding 된다
{
    short   id;     // 2 byte 
    // 컴퓨터가 잘 처리할 수 있는 형태로, 2(+2) 해서 4byte 로 처리.
    // 이걸 padding 이라고 한다.

    int     age;    // 4 byte
    double  wage;   // 8 byte
};

#endif