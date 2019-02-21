#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_map>
//problem URL : https://leetcode.com/problems/maximal-square/
using namespace std;

int maximalSquare(vector<vector<char>>& matrix) {
	if (matrix.size() == 0)
		return 0;

	if (matrix[0].size() == 0)
		return 0;

	int n = matrix.size();
	int p = matrix[0].size();
	int max_square = 0;

	vector<vector<int>> d(n + 1, vector<int>(p + 1, 0));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < p; j++)
		{
			if (matrix[i][j] == '1')
				d[i + 1][j + 1] = min(d[i][j], min(d[i][j + 1], d[i + 1][j])) + 1;

			if (d[i + 1][j + 1] > max_square)
				max_square = d[i + 1][j + 1];
		}
	}
	return max_square * max_square;

}

int main()
{
	vector<vector<char>> matrix{ {'1','0','1','1','0'},{'0','0','1','0','1'},{'1','1','1','1','0'},{'1','1','1','0','0'},{'0','0','1','0','0'} };
	cout << maximalSquare(matrix);
	return 0;
}
