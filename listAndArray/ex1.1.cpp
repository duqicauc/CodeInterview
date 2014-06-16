//实现一个算法：确定一个字符串的所有字符是否全都不相同。假使不允许使用额外的数据结构，又该如何处理？

#include <iostream>
#include <string>
using namespace std;

bool isAllDifferent(string str);
bool isAllDifferent2(string str);
bool isAllDifferent3(string str);

int main(int argc, char const *argv[])
{
	string str1("abcdeffg");
	string str2("abcde");

	if (!isAllDifferent3(str1))
	{
		cout << "str1 is not all different." <<endl;
	}

	if (isAllDifferent3(str2))
	{
		cout << "str2 is all different." <<endl;
	}
	return 0;
}

bool isAllDifferent(string str)
{
	if (str.length() > 256)
		return false;

	//1 统计各个字符各自的出现次数
	int array[256] = {0};

	for (int i = 0; i < str.length(); ++i)
	{
		array[str[i]-'a']++;
	}

	//2 判断
	for (int i = 0; i < 26; ++i)
	{
		if (array[i] > 1)
		{
			return false;
		}
	}
	return true;
}

bool isAllDifferent2(string str)
{
	if (str.length() > 256)
		return false;

	bool array[256] = {false};

	for (int i = 0; i < str.length(); ++i)
	{
		int val = str[i];
		if (array[val])
		{
			return false;
		}
		array[val] =  true;
	}
	return true;	
}

//假定待判断的字符串中只有a~z个字母
bool isAllDifferent3(string str)
{
	if (str.length() > 26)
		return false;

	int checker = 0;

	for (int i = 0; i < str.length(); ++i)
	{
		int val = str[i] - 'a';
		if ((checker & (1 << val)) > 0) //注意优先级，比较运算符优先级大于 位运算符
		{
			return false;
		}
		checker |= (1 << val);
	}
	return true;
}
