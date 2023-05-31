#include <iostream>
#include <limits>

void caseError1()
{
    /*
    문제 발생 ( 문자열에 띄워쓰기 입력 )
    목표 : 이름 입력 -> 나이 입력 -> 이름 나이 출력
    문제 : 이름 입력(Jack Jack) -> Jack Jack 출력되면서 종료 됨
    과정 : 첫번째 cin : [Jack, ' ', Jack, '\n']
                      Jack 이 name 에 들어가고
          두번째 cin : 앞의 두 번째 Jack 이 age 에 자동으로 들어가고
                     '\n' 으로 인해 바로 종료
    */
    using namespace std;
    cout << "Your name : ";
    string name;
    cin >> name;

    cout << "Your age : ";
    string age;
    cin >> age;

    cout << name << " " << age << endl; 
}

void caseError2()
{
    /*
    문제 발생 ( cin 에 int 변수에 대한 입력 )
    목표 : 숫자 입력(int) -> 나이 입력(string) -> 이름, 나이 출력 
    문제 : 첫번째 cin 에서 int 를 입력했는데 버퍼가 비워지지 않는다
    원인 : int 변수라서, 들어오는 값에 '\n' 이 없는 채로 들어오는 듯..?
    결과 :
          Your age? : 20
          Your name? :  20
          출력하고 바로 종료 ...
    */
    using namespace std;
    cout << "Your age? : ";
    int age;
    cin >> age;

    cout << "Your name? : ";
    string name;
    getline(cin, name);

    cout << name << " " << age << endl;
 }

void caseResolved1()
{
    /*
    해결 : 입력에서 중간 whitespace 무시하고 '\n' 단위로 구분
          -> getline
    */
    using namespace std;

    cout << "Your name : ";
    string name;
    getline(cin, name);

    cout << "Your Age : ";
    string age;
    getline(cin, age);

    cout << name << " " << age << endl;
}

void caseResolved2()
{
    /*
    해결 : 중간 int 입력 받고, 버퍼 비워주면 돼
    */
    using namespace std;
    cout << "Your age? : ";
    int age;
    cin >> age;

    // 32767 글자만큼 무시해라 '\n' 오기 전까지
    // 32767 : 2byte int 로 표현가능한 가장 큰 값
    // cin.ignore(32767, '\n'); 

    // cin    은 '\n'를 처리하지 않고 입력버퍼에 남겨둔다.
    // geline 은 '\n'를 입력버퍼에서 가져와서 처리한다.  

    // magic number 가 찝찝하니, 교체하면
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


    cout << "Your name? : ";
    string name;
    getline(cin, name);

    cout << name << " " << age << endl;
}