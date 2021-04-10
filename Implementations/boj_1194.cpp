#include <string>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> board;
vector<pair<int, int>> eds;
pair<int, int> start;
bool visited[50][50][1 << 6] = { 0 };

int dir_y[4] = { -1,0,1,0 };
int dir_x[4] = { 0,1,0,-1 };

bool isValid(int y, int x, int r, int c) {
    return (y >= 0 && y < r&& x >= 0 && x < c && board[y][x] != '#');
}

bool hasKey(int state, char door) {
    return (state & (1 << (door - 'A')));
}

int main() {
    int n, m;
    cin >> n >> m;
    board.resize(n, vector<int>(m, 0));

    for (int r = 0; r < n; r++) {
        string inp;
        cin >> inp;
        for (int c = 0; c < m; c++) {
            board[r][c] = inp[c];
            if (board[r][c] == '1') {
                eds.push_back({ r,c });
            }
            else if (board[r][c] == '0') {
                start.first = r;
                start.second = c;
            }
        }
    }

    //pair's first = coord, second = moves
    queue<pair<pair<int, int>, pair<int,int>>> q;
    visited[start.first][start.second][0] = true;
    q.push({ make_pair(start.first,start.second), make_pair(0,0) });

    while (!q.empty()) {
        auto cur = q.front(); q.pop();
        int y = cur.first.first;
        int x = cur.first.second;
        int cnt = cur.second.first;
        int keystate = cur.second.second;
        
        for (auto& e : eds) {
            if (y == e.first && x == e.second)
            {
                cout << cnt;
                return 0;
            }
        }

        for (int d = 0; d < 4; d++) {
            int dy = y + dir_y[d];
            int dx = x + dir_x[d];

            if (isValid(dy, dx, n, m) && visited[dy][dx][keystate] == 0) {
                //is key
                if (board[dy][dx] >= 'a' && board[dy][dx] <= 'f') {
                    int keyToAdd = (1 << (board[dy][dx] - 'a'));
                    q.push({ {dy,dx}, {cnt + 1, keystate | keyToAdd} });
                    visited[dy][dx][keystate | keyToAdd] = 1;
                }

                //is door
                if (board[dy][dx] >= 'A' && board[dy][dx] <= 'F') {
                    if (hasKey(keystate, board[dy][dx])) {
                        q.push({ {dy,dx}, {cnt + 1, keystate} });
                        visited[dy][dx][keystate] = 1;
                    }
                }

                //'. or 0... etc'
                else {
                    q.push({ {dy,dx}, {cnt + 1, keystate} });
                    visited[dy][dx][keystate] = 1;
                }
            }
        }
        
    }
    cout << -1;

    return 0;
}

