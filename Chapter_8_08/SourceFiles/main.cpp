#include "../HeaderFiles/Calculator.h"

int main()
{
    Calc cal(10);
    cal.add(10).mul(2).sub(19).print();

    Calc(20).add(10).sub(1).print();

    return 0;
}