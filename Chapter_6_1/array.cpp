#include <iostream>
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

    // 배열의 크기는 runtime 에 결정되면 에러가 뜬다.
    // ex) 
    //      int arrSize;
    //      cin >> arrSize;
    //      students_score[arrSize]; // runtime 결정 됨(by cin)
    // 수정)
    //      int arrSize = 10;
    //      students_score[arrSize]; // 나중에 동적할당으로 하면 돼

    return 0;
}