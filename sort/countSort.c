#include <stdlib.h>
#include <string.h>
#include <stdio.h>
/**************************************************************
 功能：计数排序。
 参数： data ： 要排序的数组
        size ：数组元素的个数
        k   ：数组中元素数组最大值 +1 （这个需要+1）
 返回值： 成功0；失败-1.       
 *************************************************************/
int ctsort(int *data, int size, int k)
{
    int * counts = NULL,/*计数数组*/
        * temp = NULL;/*保存排序后的数组*/
    int i = 0;
    /*申请数组空间*/
    if ((counts = (int *) malloc( k * sizeof(int))) == NULL)
        return -1;
    if ((temp = (int *) malloc( k * sizeof(int))) == NULL)
        return -1;
    /*初始化计数数组*/
    for (i = 0; i < k; i ++)
        counts[i] = 0;
    /*数组中出现的元素，及出现次数记录，counts[k]代表数据k在data数组中出现的次数*/
    for(i = 0; i < size; i++)
        counts[data[i]] += 1;
	for (i = 0;i < k;i ++)
        printf("%d\t",counts[i]);
	printf("\n");

    /*调整元素计数中，加上前一个数，至此，counts[k]-1代表数据k在最终数组中的位置*/
    for (i = 1; i < k; i++)
        counts[i] += counts[i - 1];
	for (i = 0;i < k;i ++)
        printf("%d\t",counts[i]);
	printf("\n");

    /*使用计数数组中的记录数值，来进行排序，排序后保存的temp*/
    for (i = size -1; i >= 0; i --){
        temp[counts[data[i]] - 1] = data[i]; 
        counts[data[i]] -= 1; //放完一个元素，下一个相同的元素往前一个位置放
    }

    memcpy(data,temp,size * sizeof(int));
    free(counts);
    free(temp);
    return 0;
}
int main()
{
    int a[8] = {2,0,2,1,4,6,7,4};
    int max = a[0],
        i = 0;
    /*获得数组中中的数值*/
    for ( i = 1; i < 8; i++){
        if (a[i] > max)
            max = a[i];
    }
    ctsort(a,8,max+1);
    for (i = 0;i < 8;i ++)
        printf("%d\n",a[i]);
}
