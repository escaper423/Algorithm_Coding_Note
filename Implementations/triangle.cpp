#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <iomanip>
#include <queue>
#include <chrono>
//problem URL : https://leetcode.com/problems/triangle/
#pragma warning(disable:4996)
using namespace std;

int minimumTotal(vector<vector<int>> triangle) {
	int n = triangle.size();
	vector<int> sum(n, 0);
	int btm_right;
	for (int i = n - 1; i >= 0; --i)
	{
		btm_right = (i == n - 1) ? 0 : sum[i + 1];

		for (int k = i; k >= 0; --k)
		{
			int btm = sum[k];
			sum[k] = min(btm_right, sum[k]) + triangle[i][k];
			btm_right = btm;
		}
	}
	return sum[0];
}

int main()
{
	cout << minimumTotal({ {2},{3,4},{6,5,7},{4,1,8,3} });
	return 0;
}
