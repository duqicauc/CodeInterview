/**
 * 题目：输入数字n，按顺序打印出从1到最大的n位十进制数。
 * 例如：输入的是3，则打印出1、2、3……999
 *
 * 大数问题，实际上是使用字符串模拟数字表示问题
 *
 * */

#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

/* Increment(number)负责增加数字以及判断何时到达最大的n位数 */
bool Increment(char* number)
{
    bool isOverFlow = false;        //标识是否到达最大的n位数
    int nTakeOver = 0;              //表示进位
    int nLength = strlen(number);   //数字的位数
    
    for(int i = nLength - 1; i >= 0; i--)
    {
        int nSum = number[i] - '0' + nTakeOver; //计算每一位的数
        if(i == nLength - 1) //加1操作从个位开始发生，如果有进位才会传递到别的位
            nSum++;

        if(nSum >= 10)
        {
            if(i == 0)
                isOverFlow = true;
            else
            {
                nSum -= 10;
                nTakeOver =  1;
                number[i] = '0' + nSum;
            }
        }
        else
        {
            number[i] = '0' + nSum;
            break;
        }
    }

    return isOverFlow;
}

/*
 * 把字符串表达的数字打印出来
 * 只有碰到第一个非0的字符之后才开始打印
 * */
void PrintNumber(char* number)
{
   int i = 0;
   //处理数字前面的0，例如0098输出为98
   while(number[i] == '0')
       i++;
   
   while(number[i] != '\0')
       cout << number[i++];
   cout << "\t";
}

/* print1ToMaxOfNDigits(int n) */
void print1ToMaxOfNDigits(int n)
{
    /* 输入参数检查 */
    if(n <= 0)
        return;
    /* 初始化内存空间 */
    char* number = new char[n+1];
    memset(number, '0', n);
    number[n] = '\0';
    
    while(!Increment(number))
        PrintNumber(number);
    cout<<endl;
    
    delete []number;
}

void print1ToMaxOfNDigits_recursively(char* number, int length,int index)
{
    if(index == length - 1)
    {
        PrintNumber(number);
        return;
    }

    for(int i = 0; i < 10; ++i)
    {
        number[index + 1] = i + '0';
        print1ToMaxOfNDigits_recursively(number, length, index+1);
    }
}

/* n位所有十进制数其实就是n个从0到9的全排列 */
void print1ToMaxOfNDigits2(int n)
{
    if(n <=0)
        return ;

    char* number = new char[n+1];
    number[n] = '\0';

    for(int i = 0; i < 10; i++)
    {
        number[0] = i + '0';
        print1ToMaxOfNDigits_recursively(number, n, 0);
    }
    cout << endl;

    delete[] number;
}

int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        cout << "./bigData <位数>" <<endl;
        return -1;
    }

    int n = atoi(argv[1]);
    //print1ToMaxOfNDigits(n);
    print1ToMaxOfNDigits2(n);
    return 0;
}
