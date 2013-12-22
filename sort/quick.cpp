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

/*  partition函数： 
 *  在data序列的[start, end]之间随机选取一个元素值作为分界元素vp， 
 *  该分界元素vp左边的值都小于等于vp, 右边的值都大于等于vp,  函数
 *  返回该分界元素在序列中的索引位置 
 */
int Partition(int data[], int length, int start, int end)
{
    if (data == NULL || length <= 0 || start < 0 || end >=length)
    {
        cout << "Invalid Parameters!" <<endl;
        throw exception();
    }
    
    // 随机选取一个值，作为分割数组的关键值
    // 并且，这个关键字首先放在末尾,key = data[index]--> key = data[end]
    int index = randomInRange(start, end);
    swap(&data[index], &data[end]);
    
    // 扫描数组，将所有小于data[end]的数放在key的左边
    int small = start - 1;
    for (int i = start; i < end; i++)
    {
        if(data[i] < data[end])
        {
            small++;
            if(small != i)
                swap(&data[small],&data[i]);
        }
    }
    
    small++;
    swap(&data[small],&data[end]);
    
    return small;
}

/*  快速排序递归算法： 
 *  1. 时间复杂度是O(n*log2n) 
 *  2. 快速排序是不稳定排序，不适合在链表结构上实现的排序算法 
 *  3. 每次排序时如果各个部分的分界元素恰好就是最大值元素时，快
 *  速排序就会倒退为"慢速排序", 此时并未把序列分界为两个子序列 
 **/
void quickSort(int data[], int length, int start, int end)
{
    if(start == end)
        return;

    int index = Partition(data,length,start,end);
    if(index > start)
        quickSort(data, length, start, index - 1);
    if(index < end)
        quickSort(data, length, index + 1, end);
}

int main()
{
    int i;
    int data[]={6,5,7,3,8,9,1,10,2,15};
    cout << "排序前:";
    for(i = 0; i < 10; i++)
        cout << data[i] << " ";
    cout <<endl;

    quickSort(data,10,0,9);

    cout << "排序后:";
    for(i = 0; i < 10; i++)
        cout << data[i] << " ";
    cout <<endl;
    return 0;
}
