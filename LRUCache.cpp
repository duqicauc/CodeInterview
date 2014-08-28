/*
C++实现LRUCache
关键点：
（1）使用双链表存储缓存节点
（2）使用hash_map加快查找速度

LRU算法关键：
（1）最新访问（get或者set）的缓存节点要移动到链表首部
（2）当缓存满时，将链表尾部的节点（最近没有访问）剔除，并把新节点插入到链表首部
*/

#include <iostream>
#include <list>
#include <hash_map>
#include <utility>

using namespace std;

class LRUCache{
public:
	LRUCache(int num)
	{
		capacity = num;
	}
	int get(int key);
	void set(int key, int value);

private:
	int capacity; //缓存大小
	list<pair<int, int>> caches; //缓存由双链表表示
	//为了加快查找，使用hash_map
	hash_map<int, list<pair<int,int>>::iterator> cachesMap; 
};

int LRUCache::get(int key)
{
	int retValue = -1;
	hash_map<int,list<pair<int, int>>::iterator> ::iterator it = cachesMap.find(key);

	if(it != cachesMap.end())
	{
		retValue = it->second->second;
		//将最近访问的节点移动链表首部
		list<pair<int,int>>::iterator tmpPtr = it->second;
		pair<int, int> tmpPair = *tmpPtr;
		caches.erase(tmpPtr);
		caches.push_front(tmpPair);
		//更新hash_map中的映射
		cachesMap[key] = caches.begin();
	}

	return retValue;
}

void LRUCache::set(int key, int value)
{
	hash_map<int,list<pair<int, int> >::iterator> ::iterator it = cachesMap.find(key);

	if(it != cachesMap.end())
	{
		list<pair<int, int> >::iterator pairPtr = it->second;
		pairPtr->second = value;
		//新加入的节点放在链表首部
		pair<int,int> newPair = *pairPtr;
		caches.erase(pairPtr);
		caches.push_front(newPair);
		//更新hash_map中的映射
		cachesMap[key] = caches.begin();
	}
	else
	{
		if(capacity == caches.size())
		{
			//如果caches已经满，则将链表末尾的元素删除
			int delKey = caches.back().first;
			caches.pop_back();

			hash_map<int, list<pair<int,int>>::iterator>::iterator delIt = cachesMap.find(delKey);
			cachesMap.erase(delIt);
		}
		pair<int, int> temp_pair = make_pair(key,value);
		caches.push_front(temp_pair);
		cachesMap[key] = caches.begin();
	}
}


int main()
{
	LRUCache s(3);  
    s.set(4, 1);  
    s.set(3, 2); 
	s.set(0, 3);
	cout << s.get(4) << endl;
	cout << s.get(3) << endl;

	s.set(1, 5);
    cout << s.get(0) << endl;  
	cout << s.get(1) << endl; 
	s.set(6, 7);
	cout << s.get(4) << endl;
	return 0;
}
