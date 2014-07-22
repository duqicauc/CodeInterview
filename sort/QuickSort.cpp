#include <iostream>
#include <ctime>
using namespace std;

/*划分函数，从左和右同时扫描，并使用随机数选取划分关键字*/
int partition(int a[],int first, int last)
{
	int l=first,r=last;
	srand((unsigned)time(0));
	int key = a[(rand() % (r-l+1))+ l];  //(1)去[l,r]之间的随机数
	//int key = a[(l+r)/2];  //(2)取中间值为分割点

	while(l < r){
		// 从右往左，找到第一个小于或者等于key的值，应该放到左边去
		while(a[r]>key) r--;
		// 从左往右，找到第一个大于或者等于key的值，应该放到右边去
		while(a[l]<key) l++;

		if(l < r){
			int temp = a[l];
			a[l] = a[r];
			a[r] = temp;
		}
	}
	a[l] = key; //关键字放在正确的位置上
	return l;
}

void QuickSort(int L[],int first,int last)
{
	if(first < last){
		int split = Partition(L, first, last);
		QuickSort(L, first, split-1);
		QuickSort(L, split+1,last);
	}
}
int main()
{
	int L[]={42,19,71,49,76,90,29,88,51};
	for(int i=0; i< 9; i++)
		cout << L[i] << " ";
	cout <<endl;
	
	QuickSort(L,0,8);
	
	for(int i=0; i< 9; i++)
		cout << L[i] << " ";
	cout <<endl;
	return 0;
}
