#include <iostream>
using namespace std;

void get_next(char *T, int next[])
{
	int i = 0;
	next[0] = -1;
	int j = -1;

	while(T[i+1] != '\0')
	{
		if(j == -1 || T[i] == T[j])
		{
		// (1)next数组的定义：next[i]=j说明在字符T[i]之前存在一个长度最大的子串
		// 使得等式"t0t1…tj-1"="ti-jti-j+1…ti-1"成立
		// (2)如果T[i]=T[j]则说明在字符T[i+1]之前存在着一个长度最大的子串使得
		// 等式 "t0t1…tj"="ti-jti-j+1…ti"成立,按照next[i]的定义，则有
		// next[i+1]=j+1
			++i;
			++j;
			next[i] = j;
		}
		else
		{
		//如果ti!=tj，则等式"t0t1…tj"="ti-jti-j+1…ti" 不成立，也就是说，
		//在字符T[i+1]之前不存在一个子串" ti-jti-j+1…ti"和子串"t0t1…tj"相等，
		//那么是否可能存在另一个值p<j，使等式"t0t1…tp"=" ti-pti-p+1…ti" 成立，
		//这个p显然应该是 next[k]，因为这相当于一个"利用next函数值进行T串和T串的匹配"问题。
		//如果这个P值找不到，那么就从j=-1重新开始找
			j = next[j];
		}
	}
}

/* 求出t在source中第pos个位置后的第一个匹配位置*/
int index_kmp(char *s, char *t, int pos,int tnum)
{
	int *next = new int[tnum];
	for(int m=0; m<tnum; m++)
		next[m] = 0;
	get_next(t,next);

	int i = pos;
	int j = 0;
	while(s[i]!='\0' && t[j]!='\0')
	{
		if(j==0 || s[i] == t[j])
		{
			i++;
			j++;
		}
		else
			j = next[j];
	}

	if(t[j] == '\0')
		return i-tnum;
	else
		return -1;
}

int main()
{
	char s[] = "acabaabaabcacaabc";
	char t[] = "abaabcac";
	int tnum = sizeof(t)/sizeof(t[0]) - 1;
	
	int index = index_kmp(s,t,0,tnum);
	cout << index <<endl;
	return 0;
}
