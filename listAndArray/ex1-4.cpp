/*编写一个方法，将字符串中的空格全部替换为“%20”。假定该字符串尾部有足够的空间存放
新增字符，并且知道字符串的“真实”长度*/

// 思路：涉及到字符串替换查找的问题时，有个常见的想法是从后面向前遍历处理，因为尾部
// 有足够的缓冲空间;如果从前向后便利，则必须是O（n2）的时间复杂度

#include <iostream>
#include <string>

using namespace std;

void replaceSpace(char str[], int length);

int main(int argc, char const *argv[])
{
	char test[] =  "Mr John Smith";
	cout << test << endl;
	replaceSpace(test, sizeof(test)/sizeof(test[0]));
	cout << test << endl;
	return 0;
}

void replaceSpace(char str[], int length)
{
	int now_length = length;

	for (int i = 0; i < length; ++i)
	{
		if (str[i] == ' ')
		{
			now_length += 2;
		}
	}

	str[now_length--] = str[length];

	for (int i = length-1; i >= 0; i--)
	{
		if (str[i] == ' ')
		{
			str[now_length--]='0';
			str[now_length--]='2';
			str[now_length--]='%';
		}
		else
		{
			str[now_length--]=str[i];
		}
	}
}