#include <iostream>

using namespace std;

void print_vector(std::vector<long long> &v)
{
    for (auto &e: v)
    {
        cout << e << " ";
    }
    cout << endl;
}

void fibonacci(std::vector<long long> &v)
{
    v[0] = 0;
    v[1] = 1;

    for (int i = 2; i < v.capacity(); i++)
    {
        v[i] = v[i - 1] + v[i - 2];
    }
}


int main()
{
    int num;
    std::vector<long long> v;

    cin >> num;
    v.resize(num + 1);

    fibonacci(v);
    print_vector(v);

    return 0;
}