#include <iostream>
using namespace std;

int getInt();
char getOperator();
void printResult(int x, char op, int y);

int main()
{
    int x = getInt();
    int y = getInt();
    int op = getOperator();

    printResult(x, op, y);

    return 0;
}

int getInt()
{
    // cin으로 받은 int 의 범위가 cin 버퍼 사이즈를 초과한다면?
    // 문제가 생긴다. 10000000000000000000000000 넣어봐
    // 그래서 제대로 된 값을 받을 때까지 재입력 받도록 설계

    // cin은 '\n'를 처리하지 않고 입력버퍼에 남겨둔다.
    // geline은 '\n'를 입력버퍼에서 가져와서 처리한다.  
    
    while(true)
    {
        cout << "Enter the num: ";
        int num;
        cin >> num;

        if (cin.fail())
        {
            cin.clear(); // 이전 cin 버퍼의 값들을 비워준다
            cin.ignore(32767, '\n'); // 
            cout << "Invalid input. Please try again.";
        }
        else
        {
            // 여기서 버퍼를 비워주는 역할 -> 공백이 들어가면 하나만 받게된다
            cin.ignore(32767, '\n');
            return num;
        }
    }
}

char getOperator()
{
    while (true)
    {
        cout << "Enter operator(+, -): ";
        char op;
        cin >> op;

        if (op == '+' || op == '-') 
            return op;
        else
            cout << "Invalid operator. Please try again." << endl;
    }
}

void printResult(int x, char op, int y)
{
    switch (op)
    {
    case '+':
        cout << x << " + " << y << " = " << x + y << endl;
        break;
    case '-':
        cout << x << " - " << y << " = " << x - y << endl;
        break;
    default:
        cout << "Invalid operator" <<endl;
        break;
    }
}