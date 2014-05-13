/**
求子数组的最大和：


*/
#include <iostream>
#include <assert.h>

using namespace std;

#define max(a,b) ((a) > (b)) ? (a) : (b)
int findMaxSumOfSubArray(int *array, int num);

int main(int argc, char const *argv[])
{
	int  array[]={-1,-2,-3,-10,-4,-7,-2,-5};
	cout << "the max sum of sub array is: " << findMaxSumOfSubArray(array,sizeof(array)/sizeof(array[0])) <<endl;
	return 0;
}

int findMaxSumOfSubArray(int *array, int num)
{
	assert(array != NULL && num >0);\
	
	int max = array[0];
	for (int i = 1; i < num; ++i)
	{
		// use array[i] to locate the current sum, decide if the max has the truly array[i]
		array[i] = max(array[i],array[i-1]+array[i]); 
		if (max < array[i])
		{
			max = array[i];
		}				
	}

	return max > 0 ? max : 0;
}
