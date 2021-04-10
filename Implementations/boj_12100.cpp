#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dir_y[4] = { -1,0,1,0 };
int dir_x[4] = { 0,1,0,-1 };

int mx = 2;
int n;

bool isValid(int x) {
	return x > 0 && x <= n;
}

string traces[4] = { "up","right","down","left" };
void simulate(vector<vector<int>> board, int times, string trace) {

	if (times == 5) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (board[i][j] > mx)
					mx = board[i][j];
		return;
	}
	/*
	cout << "Time: " << times << " Path: " << trace << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << board[i][j] << " ";
		cout << endl;
	}
	*/
	for (int d = 0; d < 4; d++) {
		auto tmp(board);
		int to_add, y, x;
		switch (d) {
			//up 

		case 0:
			y = 0;
			to_add = 1;
			break;
			//right
		case 1:
			x = n - 1;
			to_add = -1;
			break;
			//down
		case 2:
			y = n - 1;
			to_add = -1;
			break;
			//left
		case 3:
			x = 0;
			to_add = 1;
			break;
		}

		for (int i = 0; i < n; i++) {
			
			int cur = (d % 2) ? x : y;
			int can_add = false;
			deque<int> q;
			while (cur >= 0 && cur < n) {
				int& cur_node = (d % 2) ? tmp[i][cur] : tmp[cur][i];
				if (cur_node) {
					if (can_add && (q.back() == cur_node)) {
						can_add = false;
						q.back() <<= 1;
					}
					else {
						can_add = true;
						q.push_back(cur_node);
					}
				}
				cur += to_add;
				cur_node = 0;
			}
			
			cur = (d % 2) ? x : y;
			while (!q.empty()) {
				int& cur_node = (d % 2)? tmp[i][cur] : tmp[cur][i];
				cur_node = q.front(); q.pop_front();
				cur += to_add;
			}
		}
		simulate(tmp, times + 1, trace + traces[d] + " ");
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	vector<vector<int>> arr(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++)
		for (int k = 0; k < n; k++)
			cin >> arr[i][k];

	simulate(arr, 0, "");
	cout << mx;
	return 0;
}