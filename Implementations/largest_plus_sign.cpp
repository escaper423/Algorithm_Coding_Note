#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <iomanip>
#include <queue>
#include <chrono>
//problem URL : https://leetcode.com/problems/largest-plus-sign/
#pragma warning(disable:4996)
using namespace std;

int orderOfLargestPlusSign(int N, vector<vector<int>> mines) {
	vector<vector<int>> D(N, vector<int>(N, 0));
	vector<vector<int>> grid(N, vector<int>(N, 1));

	for (auto &m : mines)
		grid[m[0]][m[1]] = 0;


	int res = 0;
	int cnt;

	for (int i = 0; i < N; i++)
	{
		cnt = 0;
		for (int k = 0; k < N; k++)
		{
			if (grid[i][k] == 1)
				cnt++;
			else
				cnt = 0;

			D[i][k] = cnt;
		}
	}

	for (int i = 0; i < N; i++)
	{
		cnt = 0;
		for (int k = N - 1; k >= 0; k--)
		{
			if (grid[i][k] == 1)
				cnt++;
			else
				cnt = 0;

			D[i][k] = min(cnt, D[i][k]);

		}
	}

	for (int i = 0; i < N; i++)
	{
		cnt = 0;
		for (int k = N - 1; k >= 0; k--)
		{
			if (grid[k][i] == 1)
				cnt++;
			else
				cnt = 0;
			D[k][i] = min(cnt, D[k][i]);
		}

	}

	for (int i = 0; i < N; i++)
	{
		cnt = 0;
		for (int k = 0; k < N; k++)
		{
			if (grid[k][i] == 1)
				cnt++;
			else
				cnt = 0;

			D[k][i] = min(cnt, D[k][i]);
			res = max(D[k][i], res);
		}
	}

	return res;
}

int main()
{
	cout << orderOfLargestPlusSign(5, { {4,2} }) << endl;
	cout << orderOfLargestPlusSign(1, { {0,0} }) << endl;
	return 0;
}
