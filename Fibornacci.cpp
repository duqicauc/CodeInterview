/* 求Fibornacci数列的第n项的值 */
#include <iostream>

using namespace std;

/* 求Fibonacci数列的第n项 */
long long Fibonacci(unsigned int n)
{
    if(n <= 0)
        return 0;

    if(n == 1)
        return 1;

    return Fibonacci(n - 1) + Fibonacci(n - 2);
}

/* 递推法 */
long long Fibonacci_iterator(unsigned int n)
{
    int result[2] = {0, 1};
    if(n < 2)
        return result[n];

    long long fibNMinusTwo = 0;
    long long fibNMinusOne = 1;
    long long fibN = 0;
    for(unsigned int i=2; i <= n; i++)
    {
        fibN = fibNMinusOne + fibNMinusTwo;

        fibNMinusTwo = fibNMinusOne;
        fibNMinusOne = fibN;
    }

    return fibN;
}
int main()
{
    int n;
    cout << "请输入一个数：" <<endl;
    cin >> n;
    cout << Fibonacci_iterator(n) <<endl;
    return 0;
}
