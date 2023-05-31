#include <iostream>

bool isEven(int num);

int main()
{
    using namespace std;

    bool b1 = true;
    bool b2(false);
    bool b3{ true };
    
    b3 = false;
    cout << b3 << endl;
    cout << b1 << endl;

    cout << std::boolalpha;
    cout << b3 << endl;
    cout << b1 << endl;

    int num;
    cout << "Your input: ";
    cin >> num;
    cout << num << " is Even? : " << isEven(num) << endl;

    return 0;
}

bool isEven(int num)
{
    return ( (num % 2) == 0 );
}