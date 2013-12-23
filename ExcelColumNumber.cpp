/* 
 * 在Excel2003中，用A表示第1列，B表示第2列……Z表示第26列，
 * AA表示第27列，AB表示第28列……以此类推。请写出一个函数，
 * 输入字母表示的列号编码，输出它是第几列。
 * */

#include <iostream>

using namespace std;

#define BASE 26

int cToColum(char *str)
{
    int number = 0;
    if(str != NULL)
    {
        for( ; *str != '\0'; str++)
        {
            if(*str >= 'A' && *str <= 'Z')
                number = number * BASE + (*str - 'A' + 1);
            else
                return -1;
        }
    }
    return number;
}

int main()
{
    char colum[80];
    cout << "输入用字母表示的列号：" <<endl;
    cin.getline(colum,80);
    cout << cToColum(colum) <<endl;
    return 0;
}
