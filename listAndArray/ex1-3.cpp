/*给定两个字符串，请编写程序，确定其中一个字符串的字符重新排列之后，能否变成另外一个字符串*/

/*思路:遍历字符串s1,每遇到一个字符，就在该字符对应的数组位置+1；遍历字符串s2，在该字符对应的
位置-1，一旦遇到小于0的情况，则直接判定为false；*/

// 变位词：参考《programming peals》中的相关问题

// 考虑问题要周全：大小写是否区分、空格是否算在内？

#include <iostream>
#include <string>
using namespace std;

bool isAnagram(const string &s1, const string &s2);

int main(int argc, char const *argv[])
{
	string s1 = "Dog ";
	string s2 = "dog";

	if (isAnagram(s1,s2))
	{
		cout << "s1 and s2 is the anagram" <<endl;
	}

	string s3 = "triangle";
	string s4 = "integral";
	
	if (isAnagram(s3,s4))
	{
		cout << "s3 and s4 is the anagram" <<endl;
	}

	string s5 = "Silent";
	string s6 = "Listen";

	if (isAnagram(s5,s6))
	{
		cout << "s5 and s6 is the anagram" <<endl;
	}
	return 0;
}

// 假设：区分大小写；空格也计算在内
bool isAnagram(const string &s1, const string &s2)
{
	if (s1.length() != s2.length())
	{
		return false;
	}

	int array[256] = {0};

	for (int i = 0; i < s1.length(); ++i)
	{
		int val = s1[i];
		array[val]++;
	}

	for (int i = 0; i < s2.length(); ++i)
	{
		int val = s2[i];
		if (--array[val] < 0)
			return false;
	}
	return true;
}
