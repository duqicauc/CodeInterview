/*给定一幅由N×N矩阵表示的图像，其中每个像素的大小为4个字节，编写一个方法，将图像
旋转90度。不占用额外内存空间是否能够做到？*/

//画图=>找到规律：从外层到内层，例如，如果向右旋转的话，则有：tmp=top;top=left;left=bottom;bottom=right

#include <iostream>

using namespace std;

const int N = 4;
void routeMatrix(int matrix[][N], int row_size);
//void routeMartix(int (*matrix)[N], int row_size);

int main(int argc, char const *argv[])
{
	int matrix[][N] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cout << matrix[i][j] << '\t';
		}
		cout << endl;
	}

	routeMatrix(matrix,N);
	
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cout << matrix[i][j] << '\t';
		}
		cout << endl;
	}

	return 0;
}

void routeMatrix(int matrix[][N], int row_size)
{
	for (int layer = 0; layer < row_size/2; ++layer)
	{
		int first = layer;
		int last = N - layer - 1;

		for (int i = first; i < last; ++i)//i用于记录这一层旋转中的第i组转移
		{
			int offset = i - first;//用于考虑移动从last向前算的第offset个元素

			int temp = matrix[first][i]; // top:第first行的第i个
			matrix[first][i] = matrix[last-offset][first]; // left:第first列的第（last-offset）个
			matrix[last-offset][first] = matrix[last][last-offset]; //bottom:第last行的地(last-offset)个
			matrix[last][last-offset] = matrix[i][last-offset];  // right:第last列的第i个
			matrix[i][last-offset] = temp; //right =  temp
		}

	}
}
