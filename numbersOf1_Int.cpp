#include <iostream>

using namespace std;

/* 推荐思路：把一个整数减去1，再和原整数做与运算，会把该整数最右边一个1
 * 变成0；那么，一个整数的二进制表示中有多少个1，就可以进行多少次这样的
 * 操作。*/
int count1Numbers(int number)
{
    int count = 0;
    while(number)
    {
        ++count;
        number = (number - 1) & number;
    }
    return count;
}

/* 常规思路：先判断整数二进制表示中最右边一位是不是1，然后
 * 将输入的整数有移1位，然后再做判断……直到整个整数变成0为止*/
// 缺陷：当n为-1时，0xFFFFFF会陷入死循环
int count1Numbers2(int n)
{
    int count = 0;
    while(n)
    {
        if(n & 1)
            count++;
        n = n >> 1;
    }
    return count;
}

int count1Numbers3(int n)
{
    int count = 0;
    int flag = 1;
    while(flag)
    {
        if(n & flag)
            count++;
        flag = flag << 1;
    }

    return count;
}

int main()
{
    int n1 =  1;
    cout << n1 << "二进制表示中1的个数：" << count1Numbers3(n1) <<endl;
    int n2 = 2147483647;
    cout << n2 << "二进制表示中1的个数：" << count1Numbers3(n2) <<endl;
    //int n3 = -2147483648;
    //cout << n3 << "二进制表示中1的个数：" << count1Numbers2(n3) <<endl;
    int n4 = -1;
    cout << n4 << "二进制表示中1的个数：" << count1Numbers3(n4) <<endl;
    int n5 = 0;
    cout << n5 << "二进制表示中1的个数：" << count1Numbers3(n5) <<endl;
    return 0;
}
