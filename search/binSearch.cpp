/* 
 * 二分搜索：
 * 我们需要确定排序后的数组x[0..n-1]中是否包含目标元素t。准确地说，
 * 已知n>=0且x[0]<=x[1]<=x[2]<=...<=x[n-1]，当n=0时数组为空。t与x
 * 中的数据类型相同。无论是整型、浮点型还是字符串型，伪代码都必须
 * 地正确运行。答案存储在下标p中：当p=-1时，目标t不在数组x[0..n-1]
 * 中；否则0<=p<=n-1，且t=x[p]。
 * */

#include <iostream>

using namespace std;

int binSearch(int data[], int t, int length)
{
    int p = -1;
    int l = 0, u = length - 1;
    while(l <= u)
    {
        int m = (l + u)/2;
        if(t > data[m])
            l = m + 1;
        else if( t == data[m]){
            p = m;
            break;
        }
        else if(t < data[m])
            u = m - 1;
    }
    return p;
}

int main()
{
    int data[] = {1, 3, 5, 6, 9, 11, 13, 189, 200,234, 500, 1999};
    //1、 t在数组中，即0<=p<=n-1
    int t = 9;
    cout << t << "在数组中的位置：" << binSearch(data,t,12) <<endl;
    //2、 t不在数组中
    t = 12;
    cout << t << "在数组中的位置：" << binSearch(data,t,12) <<endl;
    return 0;
}
