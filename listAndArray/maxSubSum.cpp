#include <iostream>
#include <exception>
using namespace std;

int maxSubSum(int arr[], int len)
{
	if(arr == NULL || len <= 0)
		throw exception("Invalid pramater!");
	int currSum = 0;
	int max = arr[0];
	for (int i = 0; i < len; i++) {
		if (currSum <= 0) { 
			//如果currSum小于0，则丢掉前面的数组
			currSum = arr[i]; 
		}
		else {
			//否则，就继续加现在这个值
			currSum += arr[i];
		}

		if(currSum > max) //处理全部元素是负数的情况
			max = currSum;
	}
	return max;
}

int main()
{
	//int arr[] = {1,-2,3,10,-4,7,2,5};
	//int arr[] = {0,-2,3,5,-1,2};
	int arr[] = {-1,-2,-3,-4,-5};
	int maxSum = maxSubSum(arr,sizeof(arr)/sizeof(arr[0]));
	cout << maxSum <<endl;
	return 0;
}
