/* 
 * 题目：实现函数double Power(double base, int exponent),求base的exponent次方。
 * 不得使用库函数，同时不需要考虑大数问题。 
 *
 * 本题主要考察思维的全面性，考虑底数和指数分别为正数、负数和零。
 * 测试用例：
 * base = 2.5, exponent = 2;    ---> 6.25
 * base = 2.5, exponent = 0;    ---> 1
 * base = 2.5, exponent = -2;   ---> 0.16
 * base = 0, exponent = 2;      ---> 0
 * base = 0, exponent = 0;      ---> 1
 * base = 0, exponent = -2;     ---> inf
 * base = -2.5, exponent = 2;   ---> 6.25
 * base = -2.5, exponent = 0;   ---> 1
 * base = -2.5, exponent = -2   ---> 0.16
 * 相应结果：（使用cmath中库函数pow跑出的结果）
 */

#include <iostream>
#include <iomanip>

using namespace std;

bool g_InvalidInput = false; //便于区分返回的0是否为出错时返回的0

double PowerWithUnsignedExponent(double, unsigned int);

double Power(double base, int exponent)
{
    // 底数为0，指数为负数的出错处理
    g_InvalidInput = false;
    if(base == 0.0 && exponent < 0)
    {
        g_InvalidInput = true;
        cout << "inf" <<endl; //表示计算是错误的！！！
        return 0.0;
    }
    
    // 求指数的绝对值
    unsigned int absExponent;
    if(exponent < 0)
        absExponent = (unsigned int)(-exponent);
    else
        absExponent = (unsigned int)exponent;

    // 求正常的base值，在指数为正的时候的值，然后再根据指数正负处理是否需要求倒数
    double result = PowerWithUnsignedExponent(base, absExponent);
    if(exponent < 0)
        result = 1.0 / result;

    return result;
}

double PowerWithUnsignedExponent(double base, unsigned int exponent)
{
    if(exponent == 0) //base为正/负/零，只要指数为0，则结果为1.0
        return 1.0;
    if(exponent == 1)
        return base;

    // 使用右移代替除以2；使用位与运算代替求余(%)判断奇偶数
    double result = PowerWithUnsignedExponent(base, exponent >> 1);
    result *= result;
    if((exponent & 0x1) == 1)
        result *= base;

    return result;
}

/* 
 * 对浮点数比较大小时不要使用==；本来应该相等的两个浮点数由于计算机内部表示的原因可能
 * 有微小的误差，这时用==就会认为它们不相等。应该使用两个浮点数之间的差值的绝对值小于
 * 某个值来判断它们是否相等。
 * */
bool equal(double num1, double num2)
{
    if((num1 - num2 > -0.0000001)&&(num1 - num2 < 0.0000001))
        return true;
    else
        return false;
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
