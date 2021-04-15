#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

typedef struct nod {
	int ry, rx;
	int by, bx;
	int cnt;
	nod(int ary, int arx, int aby, int abx, int c) :
		ry(ary), rx(arx), by(aby), bx(abx), cnt(c)
	{}
} nod;

char board[11][11] = { 0 };

int visited[11][11][11][11] = { 0 };

int dir_x[4] = { 0,1,0,-1 };
int dir_y[4] = { -1,0,1,0 };
	
int n, m;
int hy, hx;

int moveOrb(int *src_y, int *src_x, int dir) {
	int moved = 0;

	while (1) {
		if (*src_y == hy && *src_x == hx)
			break;

		int ny = *src_y + dir_y[dir];
		int nx = *src_x + dir_x[dir];

		if (board[ny][nx] == '#')
			break;

		*src_y = ny;
		*src_x = nx;
		moved++;
	}
	return moved;
}

int main() {
	cin >> n >> m;
	int ry = 0, rx = 0;
	int by = 0, bx = 0;

	for (int i = 0; i < n; i++) {
		string inp; cin >> inp;
		for (int k = 0; k < m; k++) {
			board[i][k] = inp[k];

			//red
			if (board[i][k] == 'R') {
				ry = i; rx = k;
				board[i][k] = '.';
			}

			//blue
			if (board[i][k] == 'B') {
				by = i; bx = k;
				board[i][k] = '.';
			}

			//hole
			if (board[i][k] == 'O') {
				hy = i; hx = k;
			}
		}
	}
	visited[by][bx][ry][rx] = 1;
	
	queue<nod> q;
	q.push(nod(ry, rx, by, bx, 1));
	while (!q.empty()) {
		nod cur = q.front(); q.pop();
		//cout << "Red: " << cur.ry << "," << cur.rx << " Blue: " << cur.by << "," << cur.bx << " Count: " << cur.cnt << endl;
		if (cur.cnt > 10)
			break;

		for (int dir = 0; dir < 4; dir++) {
			int nry = cur.ry, nrx = cur.rx;
			int nby = cur.by, nbx = cur.bx;
			//move orbs
			int red_moves = moveOrb(&nry, &nrx, dir);
			int blue_moves = moveOrb(&nby, &nbx, dir);

			//blue reaches the hole
			if (nby == hy && nbx == hx)
				continue;

			if (nry == hy && nrx == hx) {
				cout << cur.cnt;
				return 0;
			}

			//stacked blue and red
			if (nby == nry && nbx == nrx) {
				if (red_moves < blue_moves) {
					nby -= dir_y[dir];
					nbx -= dir_x[dir];
				}
				else {
					nry -= dir_y[dir];
					nrx -= dir_x[dir];
				}
			}

			if (visited[nby][nbx][nry][nrx] == 0) {
				visited[nby][nbx][nry][nrx] = 1;
				q.push(nod(nry, nrx, nby, nbx, cur.cnt + 1));
			}

		}
	}
	cout << -1;
	return 0;
}

