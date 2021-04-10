#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int board[50][50] = { 0 };
int visited[50][50] = { 0 };

int dir_x[4] = { 0,1,0,-1 };
int dir_y[4] = { -1,0,1,0 };

int r, c;

bool isValid(int row, int col) {
	return (r >= 0 && c >= 0 && row < r && col < c);
}

bool dfs(char cur, int row, int col, int depth, int pre_dir) {
	visited[row][col] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = row + dir_y[i];
		int nx = col + dir_x[i];
		if (isValid(ny, nx) && cur == board[ny][nx]) {
			if (visited[ny][nx] == 1 && depth >= 3 && abs(pre_dir - i) != 2)
				return true;
			if (!visited[ny][nx] && dfs(board[ny][nx],ny, nx, depth + 1, i))
				return true;
		}
	}
	visited[row][col] = 2;
	return false;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	cin >> r >> c;
	for (int row = 0; row < r; row++) {
		string inp; cin >> inp;
		for (int col = 0; col < c; col++)
			board[row][col] = inp[col];
	}

	for (int i = 0; i < r; i++) {
		for (int k = 0; k < c; k++) {
			if (!visited[i][k]) {
				if (dfs(board[i][k],i, k, 1, 5)) {
					cout << "Yes";
					return 0;
				}
			}
		}
	}
	cout << "No";
	return 0;
}

