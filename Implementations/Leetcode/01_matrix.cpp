#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

//problem URL : https://leetcode.com/problems/01-matrix/

using namespace std;

int dir_x[4] = { 0,1,0,-1 };
int dir_y[4] = { -1,0,1,0 };

struct Point {
	int y;
	int x;
};

vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {

	int R = matrix.size();
	int C = matrix[0].size();

	vector<vector<int>> res(R, vector<int>(C, INT_MAX));
	queue<pair<Point, int>> q;

	for (int i = 0; i < R; i++) {
		for (int k = 0; k < C; k++) {
			if (matrix[i][k] == 0) {
				q.push(make_pair(Point{ i,k }, 0));
			}
		}
	}

	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		int row = cur.first.y, col = cur.first.x, dist = cur.second;
		res[row][col] = min(res[row][col], dist);

		for (int i = 0; i < 4; i++) {
			int ny = row + dir_y[i];
			int nx = col + dir_x[i];
			if (nx >= 0 && ny >= 0 && nx < C && ny < R) {
				if (res[ny][nx] > dist + 1) {
					res[ny][nx] = dist + 1;
					q.push(make_pair(Point{ ny,nx }, dist + 1));
				}
			}
		}
	}
	return res;
}

int main() {
	vector<vector<int>> matrix;
	int row, col;
	cin >> row >> col;
	matrix.resize(row);
	for (int i = 0; i < matrix.size(); i++)
		matrix[i].resize(col);

	for (int i = 0; i < row; i++) {
		for (int k = 0; k < col; k++) {
			cin >> matrix[i][k];
		}
	}
	auto res = updateMatrix(matrix);

	for (int i = 0; i < row; i++) {
		for (int k = 0; k < col; k++) {
			cout << res[i][k]<< " ";
		}
		cout << endl;
	}
	return 0;
}
