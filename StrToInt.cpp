#include <iostream>
#include <limits>

using namespace std;

enum Status{kInvalid = -1, kValid = 0};
int status =  kValid;

int strToInt(char* str)
{
    /* 空指针检查 */
    if (str == NULL)
    {
        status = kInvalid;
        return 0;
    }
    
    /* 正负号处理 */
    int flag = 1;
    if (*str == '-')
    {
        flag = -1;
        str++;
    }
    else if(*str == '+')
        str++;

    /* 数值操作 */
    int number = 0;
    while(*str != '\0')
    {
        if (*str >= '0' && *str <= '9')
        {
            number = number * 10 + *str - '0';
            /* 处理overflow，int类型的范围为[-2147483648,2147483647]
             * */
            if (number == 214748364)
            {
                str++;
                int fu = (flag == -1) && ((*str - '0')>8);
                int zheng = (flag == 1) && ((*str - '0')>7);
                if (fu || zheng)
                {
                    number = 0;
                    break;
                }
                str--;
            }
            str++;
        }
        else
        {
        /* 处理字符串中的非数字字符,策略是返回无效字符串状态 */
            status = kInvalid;
            return 0;
        }
    }
    return number * flag;
}

int main()
{
    char str[80];
    cout << "请输入字符串：" <<endl;
    cin.getline(str,80);
    
    int result = strToInt(str);
    if (status == kValid)
        cout << "字符串" << str << "对应的整数是：" << result <<endl;
    else
        cout << "输入有误" <<endl;
    return 0;
}
