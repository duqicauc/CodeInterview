/*利用字符重复出现次数，编写一个方法，实现基本的字符串压缩功能。
比如：
输入：“aabcccccaaa”
输出：“a2b1c5a3”
若“压缩”后的字符串没有变短，则返回原先字符串
*/

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string compress(string str);

int main(int argc, char const *argv[])
{
	string str1 = "aabcccccaaa";
	string result  = compress(str1);
	cout << result <<endl;

	return 0;
}

//使用stringstream和stringBuffer的作用一样，都只需要申请一个足够大的内存，时间复杂度是O(N)
string compress(string str)
{
	int count = 1;
	stringstream result; 
	char last = str[0];

	for (int i = 1; i < str.length(); ++i)
	{
		if (last == str[i])
		{
			count++; 
		}
		else
		{
			result << last << count;
			last = str[i];
			count = 1;
		}
	}
	result << last << count;
	//return result.str();
	if (result.str().length() < str.length())
	{
		return result.str();
	}
	return str;
}
