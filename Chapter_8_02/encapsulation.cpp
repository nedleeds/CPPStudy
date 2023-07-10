#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Date
{
private: // access specifier
    int _month;
    int _day;
    int _year;

public:
    void set_month(const int &m){ 
        this->_month = m; 
    }
    void set_day(const int &m){ 
        this->_day = m; 
    }
    void set_year(const int &m){ 
        this->_year = m; 
    }
    void set_date(const int &m, const int &d, const int &y){
        _month  = m;
        _day    = d;
        _year   = y;
    }
    const int& get_day()
    {
        return _day;
    }
    const int& get_month()
    {
        return _month;
    }
    const int& get_year()
    {
        return _year;
    }
    void print(){
        cout << _year << "." << _month << "." << _day << endl;
    }
    void copyFrom(const Date& original){
        // 같은 class 의 변수 original 을 받으면,
        // 같은 class 니깐 private 변수임에도 아래처럼 접근이 가능해
        _day    = original._day;
        _month  = original._month;
        _year   = original._year;
    }
};

int main()
{
    Date today; // { 8, 4, 2025}
    today.set_date(8, 4, 2025);
    today.print();

    Date new_date;
    new_date.copyFrom(today);
    new_date.print();

    return 0;
}