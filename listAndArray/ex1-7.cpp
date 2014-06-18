/*编写一个算法，若M×N矩阵中某个元素为0,则将其所在的行和列都清0*/

//这里，只需要注意一个陷阱，即不能一边判断是否为0一边做清零操作，因为前面的清0操作
//会对后续的判断操作有影响，不多就整个矩阵就会全部为0


#include <iostream>
using namespace std;

const int M = 3;
const int N = 4;

void process(int martix[][N], int row_size);

int main(int argc, char const *argv[])
{
	int martix[][N] = {{1,0,2,3},{4,5,6,7},{9,8,6,0}};

	process(martix,M);

	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cout << martix[i][j] << '\t';
		}
		cout << endl;
	}

	return 0;
}

void process(int martix[][N], int row_size)
{
	//int row[M] = {-1,-1,-1};
	//int col[N] = {-1,-1,-1,-1};
	bool row[M] = {false};
	bool col[N] = {false};
	//int r=0;
	//int c=0;

	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (martix[i][j] == 0)
			{
				//row[r++] = i;
				//col[c++] = j;
				row[i] = true;
				col[j] = true;
			}
		}
	}

	// 这里row 和col记录的某一行或列有零元素即可，而不记录它的具体位置
	// 所以，清零操作是再次遍历一次矩阵即可
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (row[i] || col[j])
			{
				martix[i][j] = 0;
			}
		}
	}
/*
	// 如果用row 和col依次记录的是0元素的具体的行和列，则
	// 根据对row 和col的嵌套扫描，依次将行和列清零
	for (int i = 0; i < M; ++i)
	{
		if (row[i] == -1)
		{
			break;
		}

		for (int j = 0; j < N; ++j)
		{
			martix[row[i]][j] = 0;
		}

		for (int j = 0; j < M; ++j)
		{
			martix[j][col[i]] = 0;
		}
	}
*/
}
