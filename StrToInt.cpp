#include <iostream>
#include <limits>

using namespace std;

//定义几个错误状态枚举
enum Status{kValid = 0,kNULL,kOVERFLOW,kCHAR};
int status =  kValid;

int strToInt(char* str)
{
    /* 空指针检查 */
    if (str == NULL)
    {
        status = kNULL;
        return 0;
    }

    /* 处理字符串前面的几个空格 */
    while(isspace(*str))
        str++;

    /* 正负号处理 */
    int flag = 1;
    if (*str == '-')
    {
        flag = -1;
    }
    str++;

    /* 数值操作 */
    int number = 0;
    while(*str != '\0')
    {
        if (*str >= '0' && *str <= '9')
        {
            number = number * 10 + *str - '0';
            /* 处理overflow，int类型的范围为[-2147483648,2147483647]*/
            if (number < 0)
            {
                if(flag == 1)
                    number = std::numeric_limits<int>::max();
                else if (flag == -1)
                    number = std::numeric_limits<int>::min();
                status = kOVERFLOW;
                break;
            } 
            str++;
        }
        else
        {
            /* 处理字符串中的非数字字符,策略是返回无效字符串状态 */
            status = kCHAR;
            break;
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
    switch(status){
        case kValid:
            cout << "字符串" << str << "对应的整数是：" << result <<endl;
            break;
        case kNULL:
            cout << "空指针错误" <<endl;
            break;
        case kCHAR:
            cout << "输入的字符串中有非数字字符" <<endl;
            break;
        case kOVERFLOW:
            cout << "输入的字符串对应的数字使得Int类型溢出" <<endl;
            cout << result <<endl;
    }
    return 0;
}
