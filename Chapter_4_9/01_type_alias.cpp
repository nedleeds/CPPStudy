#include <iostream>
#include <typeinfo>
#include <vector>

typedef double distance_t; // _t : type 을 명시적으로 표기
void print_value_type(const std::string &name, const distance_t x);

void ex_typedef_1()
{
    /*
    let) 거리에 대한 변수형을 double 에서 float 로 바꾸고 싶다
    -> 보통, 
    | double home2school
    | double home2company
    -> 의 double float 로 일일이 다 바꿔줘야해
    
    근데, typedef 를 쓰면, 간단하게 바꿀 수가 있다
    즉, 유지-보수에 용이하다 !!
    */

    distance_t home2school  = 3.24;
    distance_t home2company = 6.33;
    distance_t home2mart    = 1.23;
    
    print_value_type("home2school" , home2school);
    print_value_type("home2company", home2company);
    print_value_type("home2mart"   , home2mart);
}

void ex_typedef_2()
{
    /*
    타입이 길어질 때 가독성을 위해 줄여서 보여줄 수도 있다
    */
    using namespace std;

    typedef vector<pair<string, int>> pairList_t;
    // using pairList_t = vector<pair<string, int>> ;
    // using 을 써서 해도 된다. 다만 뉘앙스가 조금 다를 뿐이다
    
    pairList_t pL1{{"First", 1}};
    pL1.push_back({"Second", 2});
    pL1.push_back({"Third" , 3});

    for (auto v : pL1)
    {
        cout << v.first << ":" << v.second << endl;
    }
}

void print_value_type(const std::string &name, const distance_t x)
{
    std::cout << name << ": "; 
    std::cout << x << "(" << typeid(x).name()  << ")" << std::endl;
}
