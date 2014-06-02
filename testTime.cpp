#include <iostream>
#include <ctime>
#include <windows.h> 
using namespace std;

int f(int x)
{
	int s = 0;
	while(x-->0) s+=f(x);
	return max(s, 1);
}

/* 用于测试程序运行的时间 ，比较精确*/
int main()
{
	LARGE_INTEGER BegainTime ;     
    LARGE_INTEGER EndTime ;     
    LARGE_INTEGER Frequency ;  
	int result;

	QueryPerformanceFrequency(&Frequency);     
	QueryPerformanceCounter(&BegainTime) ;     

    result = f(31);
	QueryPerformanceCounter(&EndTime);    
    cout <<((double)( EndTime.QuadPart-BegainTime.QuadPart )/ Frequency.QuadPart)  << "s" <<endl;

	return 0;
}
