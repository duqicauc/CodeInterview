#include <iostream>
#include <string>
#include <cwctype>
#include <vector>

using namespace std;

// 去除字符串首尾的空格
string& trim(string &s)
{
	if(s.empty())
		return s;

	string::iterator iter;
	for(iter = s.begin(); iter != s.end()&& iswspace(*iter++););
	s.erase(s.begin(),--iter);

	for(iter = s.end(); iter != s.begin()&& iswspace(*--iter););
	s.erase(++iter,s.end());

	return s;
}

// 翻转字符串中的某一段子串
void reverseString(string &s, int begin, int end)
{
	for(; begin < end; begin++,end--)
	{
		char temp = s[begin];
		s[begin] = s[end];
		s[end] = temp;
	}
}

// 删除单词之间多余的空格
void delete_mult_spaces(string &s)
{
	string::iterator blank;
	string::iterator iter = s.begin();
	while(iter != s.end())
	{
		if(iswspace(*iter))
		{
			blank = iter + 1;
			while(iswspace(*blank))
				s.erase(blank);
			iter = blank;
		}
		iter++;
	}
}

void reverseWords(string &s)
{
	if (s.empty())
		return;

	s = trim(s);
	delete_mult_spaces(s);

	reverseString(s, 0, s.length()-1);

	int wbegin,wend;
	wbegin = wend = 0;
	for(size_t i = 0; i < s.length(); i++)
	{
		if(s[i] == ' ')
		{
			reverseString(s,wbegin,wend-1);
			wbegin = wend + 1;
		}
		wend++;

		// deal with the last word
		if(i == s.length()-1)
			reverseString(s,wbegin,wend-1);
	}
}

int main()
{
	vector<string> strs;
	strs.push_back("the sky is blue");
	strs.push_back("   the sky is blue");
	strs.push_back("the sky is blue   ");

	strs.push_back("the   sky is blue");
	strs.push_back("  the sky   is   blue   ");
	strs.push_back("");

	vector<string>::iterator iter;
	for(iter = strs.begin(); iter != strs.end(); iter++)
	{
		reverseWords(*iter);
		cout  << *iter << endl;
	}
	return 0;
}
