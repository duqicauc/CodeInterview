/* 用C/C++ 实现void reverse(char *str)函数， 即反转一个null('\0')结尾的字符串 */

#include <iostream>
using namespace std;

void reverse(char *str);

int main(int argc, char const *argv[])
{
	char test[] = "abcdefghig";
	cout << "f:" << test << endl;
	reverse(test);
	cout << "later:" << test << endl;
	return 0;
}

void reverse(char *str)
{
	char *start,*end;
	char temp;

	start = end = str;
	while(*end)
		end++;
	--end;

	do{
		temp = *start;
		*start = *end;
		*end = temp;
	}while(start++ < end--);
}