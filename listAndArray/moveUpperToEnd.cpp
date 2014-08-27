#include <iostream>
#include <ctype.h>
using namespace std;

void MoveSupperToEndWithOrginOrder2( char* szSrc , int nSize )
{
	int nLen = 0;
	for ( int i= 0; i < nSize; i++ ){
		//找到下一个大写字母
		if ( isupper(szSrc[i]) ){
			nLen++;
		}else{
			//将当前小写字母和前面的nLen个连续的大写字母交换
			for ( int j= i  ; j > i - nLen; j-- ){
				swap(szSrc[j],szSrc[j-1]);
			}
		}
	}
}

void main()
{
	char szSrc[] = {'A','a','b','c','F','d','j','g','\0'};
	int nSize = sizeof(szSrc)/sizeof(szSrc[0]) - 1;
	MoveSupperToEndWithOrginOrder2(szSrc,nSize);
	cout << szSrc <<endl;
}
