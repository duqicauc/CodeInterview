/*给定两个字符串s1和s2，请编写代码检查s2是否为s1旋转而成，要求只能调用一次isSubstring.
例如：waterbottle是erbottlewat的旋转后的字符串*/

// 将s1依次旋转，然后和s2作比较；旋转操作比较重要，用《programming peals》上的算法、比
// 较操作调用库函数即可

#include <iostream>
#include <string>
#include <assert.h>

using namespace std;

bool isSubstring(string &s1, const string &s2);
void rotateAtX(string &str, int index);

int main(int argc, char const *argv[])
{
	string s1 = "erbottlewat";
	string s2 = "waterbottle";

	if (isSubstring(s1,s2))
	{
		cout << "s2 is rotated by s1" <<endl;
	}
	return 0;
}

bool isSubstring(string &s1, const string &s2)
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
	cout << s1 <<endl;
	reverse(s1,index+1,s1.length()-1);
	reverse(s1,0,s1.length()-1);
}


