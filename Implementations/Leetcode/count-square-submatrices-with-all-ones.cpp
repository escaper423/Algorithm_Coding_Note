#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

//problem URL : https://leetcode.com/problems/count-square-submatrices-with-all-ones/

using namespace std;

int countSquares(vector<vector<int>>& matrix) {
	int m = matrix.size();
	if (m == 0)
		return 0;
	int n = matrix[0].size();
	vector<vector<int>> dp(m, vector<int>(n, 0));

	int res = 0;
	for (int i = 0; i < m; i++) {
		for (int k = 0; k < n; k++) {
			if (matrix[i][k] == 1) {
				if (i == 0 || k == 0) {
					res += 1;
					dp[i][k] = 1;
				}
				else {
					dp[i][k] = min(dp[i - 1][k], min(dp[i][k - 1], dp[i - 1][k - 1])) + 1;
					res += dp[i][k];
				}
			}
		}
	}
	return res;
}

int main() {
	vector<vector<int>> matrix;
	int m, n;
	cin >> m >> n;
	matrix.resize(m, vector<int>(n, 0));

	for (int i = 0; i < m; i++) {
		for (int k = 0; k < n; k++) {
			int num;
			cin >> num;
			matrix[i][k] = num;
		}
	}

	cout << countSquares(matrix);
	return 0;
}