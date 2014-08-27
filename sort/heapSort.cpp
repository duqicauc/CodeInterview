#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;
 
int parent(int);	// 返回父节点
int left(int);		// 返回左孩子节点
int right(int);		// 返回右孩子节点
//调整堆，第二个参数是指从哪个节点开始调整、第三个参数是指堆的个数
void HeapAdjust(int [], int, int);
void BuildHeap(int [], int);	// 建立堆
void print(int [], int);		// 打印出数组
void HeapSort(int [], int);		// 堆排序
 
/*返回父节点*/
int parent(int i)
{
    return (int)(i - 1) / 2;
}
 
/*返回左孩子节点*/
int left(int i)
{
    return (2 * i + 1);
}
 
/*返回右孩子节点*/
int right(int i)
{
    return (2 * i + 2);
}
 
/*对以某一节点为根的子树做堆调整(保证最大堆性质)*/
void HeapAdjust(int A[], int i, int heap_size)
{
    int l = left(i);
    int r = right(i);
    int largest;
    int temp;

	// largest记录决定A[l]和A[r]之间的较大值的下标
    if(l < heap_size && A[l] > A[i])
	{
        largest = l;
    }
    else
    {
        largest = i;
    }
    if(r < heap_size && A[r] > A[largest])
    {
        largest = r;
    }

	// 下沉（交换A[i]和A[largest]）并递归
    if(largest != i)
    {
        temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;
        HeapAdjust(A, largest, heap_size);
    }
}
 
/*建立最大堆*/
void BuildHeap(int A[],int heap_size)
{
    for(int i = (heap_size-2)/2; i >= 0; i--)
    {
        HeapAdjust(A, i, heap_size);
    }
}
 
/*输出结果*/
void print(int A[],int heap_size)
{
    for(int i = 0; i < heap_size;i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
 
/*堆排序*/
void HeapSort(int A[], int heap_size)
{
    BuildHeap(A, heap_size);
    int temp;
    for(int i = heap_size - 1; i >= 0; i--)
    {
        temp = A[0];
        A[0] = A[i];
        A[i] = temp;
        HeapAdjust(A, 0, i);
    }
    print(A, heap_size);
}
 
/*测试，对给定数组做堆排序*/
int main(int argc, char* argv[])
{
    const int heap_size = 13;
    int A[] = {19, 1, 10, 14, 16, 4, 7, 9, 3, 2, 8, 5, 11};
    HeapSort(A, heap_size);
    system("pause");
    return 0;
}
