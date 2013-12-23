/*
 *  题目：把一个数组最开始的若干元素搬到数组的末尾，我们称之为数组的
 *  旋转。输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。
 *  例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小元素为1。
 * */

#include <iostream>
#include <exception>

using namespace std;

/* minInOrder：顺序查找数组data中index1到index2之间的最小值 */
int minInOrder(int *data, int index1, int index2)
{
    int result = data[index1];
    int i;
    for(i = index1; i < index2; i++)
        if(result > data[i])
            result = data[i];
    return result;
}

int minOfRoatation(int *data, int length)
{
    if (data == NULL || length <=0)
    {
        cout << "Invalid Parameters"<<endl;
        throw exception();
    }

    int index1 = 0;
    int index2 = length - 1;
    // 循环结束条件是：递增数组也是旋转数组的一个特例，第一个元素就是最小元素
    int indexMinIndex = index1;
    while(data[index1] >= data[index2])
    {
        // 循环的另一个结束条件是index1指向前半个数组的最后一个而
        // index2指向后半个数组的第一个
        if(index2 - index1 == 1)
        {
            indexMinIndex = index2;
            break;
        }

        indexMinIndex = (index1 + index2)/2;
        if (data[index1] == data[indexMinIndex] && 
            data[index1] == data[index2] &&
            data[index2] == data[indexMinIndex])
            return minInOrder(data, index1, index2);

        // 如果数组中间元素比data[index1]大，则说明中间数位于前半个递增数组中，最小元素在它后面
        if(data[indexMinIndex] >= data[index1])
            index1 = indexMinIndex;
        // 如果数组中间元素比data[index2]小，则说明中间数位于后半个递增数组中，最小元素在它前面或者它自己
        else if(data[indexMinIndex] <= data[index2])
            index2 = indexMinIndex;
    }

    return data[indexMinIndex];
}

/* 针对已经排序好的数组这一种特殊情况，用if语句摘出来处理 */
int minOfRoatation2(int *data, int length)
{
    if(data == NULL || length <= 0)
    {
        cout << "Invalid Parameters" <<endl;
        throw exception();
    }

    int index1 = 0;
    int index2 = length - 1;
    int indexMin;
    if(data[index1] < data[index2])
    {
        indexMin = index1;    
    }
    else
    {
        while(index2 - index1 != 1)
        {
            indexMin = (index1 + index2)/2;
            if(data[index1] == data[index2] &&
               data[index1] == data[indexMin] &&
               data[index2] == data[indexMin])
                return minInOrder(data, index1, index2);
            if(data[indexMin] >= data[index1])
                index1 = indexMin;
            else if(data[indexMin] <= data[index2])
                index2 = indexMin;
        }
    }
    return data[indexMin];
}

int main()
{
    int data1[] = {3, 4, 5, 1, 2};
    cout << minOfRoatation(data1, 5) <<endl;
    cout << minOfRoatation2(data1, 5) <<endl;
    int data2[] = {1, 0, 1, 1, 1};
    cout << minOfRoatation(data2, 5) <<endl;
    cout << minOfRoatation2(data2, 5) <<endl;
    int data3[] = {1, 1, 1, 0, 1};
    cout << minOfRoatation(data3,5) <<endl;
    cout << minOfRoatation2(data3, 5) <<endl;
    int data4[] = {1, 2, 3, 4, 5};
    cout << minOfRoatation(data4, 5) <<endl;
    cout << minOfRoatation2(data4, 5) <<endl;
    int data5[] = {1};
    cout << minOfRoatation(data5, 1) <<endl;
    cout << minOfRoatation2(data5, 1) <<endl;
    //int *data6 = NULL;
    //cout << minOfRoatation(data6, 4) <<endl;
    //cout << minOfRoatation2(data6, 4) <<endl;
    return 0;
}
