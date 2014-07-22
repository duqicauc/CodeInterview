/*有个排列后的字符串数组，其中散布着一些空字符串，编写一个方法，找出给定字符串的位置。*/

//示例
//输入：在字符数组中{"at","","","","ball","","","car","","","dad","",""}，查找"ball"的索引位置
//输出：4


#include <iostream>
#include <string>

using namespace std;

int binSearchString(string strary[],int len,string key)
{
	int low = 0;
	while(strary[low] == "") low++;
	int high = len-1;
	while(strary[high] == "") high--;

	while(low < high)
	{
		int mid = (low + high)/2;
		cout << mid <<endl;
		while(strary[mid]=="") mid--;

		if(strary[mid] < key)
		{
			low = mid + 1;
			while(strary[low] == "") low++;
		}
		else if(strary[mid] > key)
		{
			high = mid - 1;
			while(strary[high] == "") high--;
		}
		else
			return mid;
	}
	return -1;
}

int main()
{
	string strarray[] = {"at","","","","ball","","","car","","","dad","",""};
	string key = "ball";
	int index = binSearchString(strarray,13,key);
	
	if( index != -1)
		cout << "location is: " << index <<endl;

	//如果要查找的是空字符串，该如何处理？
	return 0;
}
