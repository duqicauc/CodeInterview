#include <iostream>
#include <exception>
#include <ctime>
#include <cstdlib>

using namespace std;

/* randomInRange函数：生成[a,b]之间的随机数 */
int randomInRange(int a, int b)
{
    srand(time(NULL));
    return a + rand() % (b - a + 1);
}

/* swap函数，交换指针a和b指向的两个值 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Partition(int data[], int length, int start, int end)
{
    if (data == NULL || length <= 0 || start < 0 || end >=length)
    {
        cout << "Invalid Parameters!" <<endl;
        throw exception();
    }
    
    // 随机选取一个值，作为分割数组的关键值
    // 并且，这个关键字首先放在末尾
    int index = randomInRange(start, end);
    swap(&data[index], &data[end]);
    
    // 扫描数组，将所有小于
}
int main()
{
    return 0;
}
