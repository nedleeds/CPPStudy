#include <iostream>
#include <cstdint>
using namespace std;

enum Students
{
    JACKJACK,
    WILL,
    VIOLET,
    NUM_STUDENTS
};

int main()
{
    int students_score[NUM_STUDENTS];
    students_score[JACKJACK] = 0;
    students_score[WILL] = 100;
    students_score[VIOLET] = 80;

    cout << reinterpret_cast<uintptr_t>(&students_score)    << endl;
    cout << reinterpret_cast<uintptr_t>(&students_score[0]) << endl;
    cout << reinterpret_cast<uintptr_t>(&students_score[1]) << endl;
    cout << reinterpret_cast<uintptr_t>(&students_score[2]) << endl;

    cout << sizeof(students_score) << endl;

    return 0;
}