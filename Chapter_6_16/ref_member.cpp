#include <iostream>

struct Person
{
    int age, weight;
};

void ref_member()
{
    using namespace std;

    Person person{ 0, 0 };
    cout << person.weight << " " << person.age << endl;

    Person *ptr  = &person;
    Person &ref  = person;
    Person &ref2 = *ptr;

    cout << "&person : " << &person << endl;
    cout << "ptr     : " << ptr     << endl;
    cout << "ref     : " << &ref    << endl;
    cout << "ref2    : " << &ref2   << endl;

    ptr->age = 31;
    ref.weight = 71;

    cout << "age     : " << ref2.age    << endl;
    cout << "weight  : " << ref2.weight << endl;
}
