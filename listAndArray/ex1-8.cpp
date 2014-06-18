/*给定两个字符串s1和s2，请编写代码检查s2是否为s1旋转而成，要求只能调用一次isSubstring.
例如：waterbottle是erbottlewat的旋转后的字符串*/

// 算法1：将s1依次旋转，然后和s2作比较；旋转操作比较重要，用《programming peals》上的算法、比
// 较操作调用库函数即可

#include <iostream>
#include <string>
#include <assert.h>

using namespace std;

bool isRotated(string &s1, const string &s2);
void rotateAtX(string &str, int index);
bool isRotated2(const string &s1, const string &s2);

int main(int argc, char const *argv[])
{
	string s1 = "erbottlewat";
	string s2 = "waterbottle";

	if (isRotated2
(s1,s2))
	{
		cout << "s2 is rotated by s1" <<endl;
	}
	return 0;
}

bool isRotated(string &s1, const string &s2)
{
	for (size_t i = 0; i < s1.length(); ++i)
	{
		rotateAtX(s1,0);
		cout << s1 << ":" << s2 << endl;
		if (s1 == s2)
		{
			return true;
		}
	}
	return false;
}

void reverse(string &str,int start,int end)
{
	char temp;
	while(start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}

void rotateAtX(string &s1,int index)
{
	reverse(s1,0,index);
	//cout << s1 <<endl;
	reverse(s1,index+1,s1.length()-1);
	reverse(s1,0,s1.length()-1);
}

//算法2：假定s2由s1旋转而成，则在s1中必然存在一个旋转点，将s1分为x和y两部分，则s1=xy,所以s2=yx
//咋算法1中，我们考虑的是一个个寻找旋转点，这是一种比较朴素（土帽）的办法，实际上，如果我们认识
//到下面这点：yx必然是xyxy的子串，即s2总是s1s1的子串；就不用去查找旋转点了。

bool isRotated2(const string &s1, const string &s2)
{
	int len = s1.length();
	if (len == 0 || len != s2.length())
	{
		return false;
	}

	string s1s1 = s1 + s1;
	if (s1s1.find(s2) < s1s1.length())
	{
		return true;
	}
	return false;
}