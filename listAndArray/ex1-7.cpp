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
	int row[M] = {-1,-1,-1};
	int col[N] = {-1,-1,-1,-1};
	int r=0;
	int c=0;

	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (martix[i][j] == 0)
			{
				row[r++] = i;
				col[c++] = j;
			}
		}
	}

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
}
