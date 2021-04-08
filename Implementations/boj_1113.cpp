#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

vector<int> areaSizes;
int board[52][52] = { 0 };
int visited[52][52] = { 0 };

int dir_y[4] = { -1,0,1,0 };
int dir_x[4] = { 0, 1,0,-1 };

int n, m;
int res = 0;

void bfs(int height) {
	queue<pair<int, int>> q;
	visited[0][0] = 1;
	board[0][0] = height;

	q.push({ 0,0 });
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		for (int d = 0; d < 4; ++d) {
			int ny = cur.first + dir_y[d];
			int nx = cur.second + dir_x[d];
			if (ny >= 0 && nx >= 0 && ny <= n+1 && nx <= m+1 && visited[ny][nx] == 0 && height > board[ny][nx]) {
				visited[ny][nx] = 1;
				q.push({ ny,nx });
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= m; k++) {
			if (board[i][k] < height && visited[i][k] == 0) {
				res++;
			}
				
		}
	}
	memset(visited, 0, sizeof(visited));
}
int main() {
	cin >> n >> m;
	int mx = 0;
	for (int i = 1; i <= n; i++) {
		string inp; cin >> inp;
		for (int k = 1; k <= m; k++) {
			board[i][k] = (int)(inp[k-1] - '0');
			mx = max(mx, board[i][k]);
		}
	}

	//bfs 
	for (int h = 1; h <= mx; h++) {
		bfs(h);
	}
	cout << res;
	return 0;
}