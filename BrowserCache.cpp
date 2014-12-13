/*
描述
When you browse the Internet, browser usually caches some documents to reduce the time cost of fetching them from 
remote servers. Let's consider a simplified caching problem. Assume the size of browser's cache can store M pages.
When user visits some URL, browser will search it in the cache first. If the page is already cached browser will 
fetch it from the cache, otherwise browser will fetch it from the Internet and store it in the cache. When the cache
is full and browser need to store a new page, the least recently visited page will be discarded.
Now, given a user's browsing history please tell us where did browser fetch the pages, from the cache or the Internet? 
At the beginning browser's cache is empty.

输入
Line 1: Two integers N(1 <= N <= 20000) and M(1 <= M <= 5000). 
N is the number of pages visited and M is the cache size.

Line 2~N+1: Each line contains a string consisting of no more than 30 lower letters, 
digits and dots('.') which is the URL of the page. Different URLs always lead to different pages. 
For example www.bing.com and bing.com are considered as different pages by browser.

输出
Line 1~N: For each URL in the input, output "Cache" or "Internet".

提示
Pages in the cache before visiting 1st URL [null, null]
Pages in the cache before visiting 2nd URL [www.bing.com(1), null]
Pages in the cache before visiting 3rd URL [www.bing.com(1), www.microsoft.com(2)]
Pages in the cache before visiting 4th URL [www.bing.com(1), www.microsoft.com(3)]
Pages in the cache before visiting 5th URL [windows.microsoft.com(4), www.microsoft.com(3)]
The number in parentheses is the last visiting timestamp of the page.

样例输入
5 2
www.bing.com
www.microsoft.com
www.microsoft.com
windows.microsoft.com
www.bing.com
样例输出
Internet
Internet
Cache
Internet
Internet
*/


#include <iostream>
#include <string>
using namespace std;

typedef struct urlPair{
	string url;
	int timeTrap;
}urlPair;

class MyCache{
public:
	MyCache(int x){
		capacity = x;
		nums = 0;
		caches = new urlPair[x];
	}

	bool hasCached(string str,int t){
		for(int i=0; i<nums; i++){

			if(caches[i].url == str){
				caches[i].timeTrap = t;
				return true;
			}
		}

		if(nums < capacity){
			caches[nums].url = str;
			caches[nums].timeTrap = t;
			nums++;
		}
		else{
			int min = 0;
			for(int i=1; i<capacity; i++){
				if(caches[i].timeTrap < min)
					min = i;
			}

			caches[min].url = str;
			caches[min].timeTrap = t;
		}
		return false;
	}

private:
	int capacity;
	int nums; // 现在有多少个元素
	urlPair *caches;
};

int main()
{
	int cap,nums;
	cin>>nums>>cap;

	MyCache cache(cap);
	string *strs = new string[nums];

	for(int i=0; i<nums; i++){
		string tmp;
		cin>>tmp;
		if(tmp == "")
			continue;
		strs[i] = tmp;
	}

	for(int i=0; i<nums; i++){
		if(cache.hasCached(strs[i],i+1)){
			cout<<"Cache"<<endl;
		}
		else
		{
			cout<<"Internet"<<endl;
		}
	}

	return 0;
}
