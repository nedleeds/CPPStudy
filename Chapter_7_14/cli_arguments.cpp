#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    // argc : argument 수
    // argv : arguments 
    for (int i = 0; i < argc; i++)
    {
        cout << argv[i] << endl;
    }
}