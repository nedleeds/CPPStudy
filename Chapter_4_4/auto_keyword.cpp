#include <iostream>

// 가독성이 증가한다는데...
// int add( ), double add()
// 이게 더,,, 빠른거 아닌가 ,,,?
// 오버로딩이 많은 경우 추천하는거라 생각하자
auto add(int a, int b) -> int;
auto add(int a, double b) -> double;

int main()
{
    using namespace std;

    auto a = 123;
    auto d = 123.0;
    auto c = 1 + 2.0;
    auto result  = add(1, 2);
    auto result2 = add(1, 2.0);

    return 0;
}

auto add(int a, int b) -> int
{
    return a + b;
}

auto add(int a, double b) -> double
{
    return a + b;
}