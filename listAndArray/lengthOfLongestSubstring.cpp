#include <iostream>
#include <hash_map>

using namespace std;

int lengthOfLongestSubstring(char *arr, int len, int &maxindex) {
	int curlen = 0;
	int maxlen = 0;
	int startindex = 0;
	
	hash_map<char,int> hm;
	hash_map<char,int>::iterator it;
	
	for (int i = 0; i < len; i++) 
	{
		it = hm.find(arr[i]);
		if (it == hm.end()) 
		{
			curlen++;
			hm[arr[i]] = i;
		} 
		else 
		{
		    //这里要考虑新开始的子串的startindex和当前这个字符的下hm[arr[i]]标谁大
			startindex = startindex > hm[arr[i]] ? startindex : hm[arr[i]]+1;
			curlen = i - startindex + 1; //更新curlen
			hm[arr[i]] = i;
		}

		if(curlen > maxlen)
		{
			maxlen = curlen;
			maxindex = startindex;
		}
	}
	return maxlen;
}

int main()
{
	char arr[] = "addbcabcbb";
	int index = 0;

	int maxlen = lengthOfLongestSubstring(arr,10,index);

	for(int i = 0; i < maxlen; i++)
		cout << arr[i + index] <<endl;
	cout <<  maxlen << "\t" << index <<endl;
	return 0;
}
