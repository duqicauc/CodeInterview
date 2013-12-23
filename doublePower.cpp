/* 
 * 题目：实现函数double Power(double base, int exponent),求base的exponent次方。
 * 不得使用库函数，同时不需要考虑大数问题。 
 */

#include <iostream>
#include <iomanip>

using namespace std;

double Power(double base, int exponent)
{
    double result = 1.0;
    for(int i = 1; i <= exponent; i++)
        result *= base;
    return result;
}

int main()
{
    double base;
    int exponent;
    cout << "输入基数值base：" <<endl;
    cin>>base;
    cout << "输入指数值exponent：" <<endl;
    cin>>exponent;
    double result = Power(base, exponent);
    cout << setprecision(4) << result <<endl;
    return 0;
}
