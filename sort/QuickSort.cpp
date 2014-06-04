#include <iostream>
#include <ctime>
using namespace std;

/*划分函数，从左和右同时扫描，并使用随机数选取划分关键字*/
int Partition(int L[],int first, int last)
{
	int l=first,r=last;

	srand((unsigned)time(0));
	int key = L[rand()%r + l];
	
	while(l < r){
		while((r>l) && L[r]>=key) r--;
		if(l<r)
			L[l++] = L[r];
		while((l<r) && L[l]<key) l++;
		if(l<r)
			L[r--] = L[l];
	}
	L[l]=key;
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
	QuickSort(L,0,8);
	for(int i=0; i< 9; i++)
		cout << L[i] << endl;
	return 0;
}
