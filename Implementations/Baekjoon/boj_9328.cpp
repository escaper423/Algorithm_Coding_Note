#include <string>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<char>> board;
bool visited[102][102] = { 0 };
bool keys[26] = { 0 };

int dir_y[4] = { -1,0,1,0 };
int dir_x[4] = { 0,1,0,-1 };

bool isValid(int y, int x, int r, int c) {
    return (y >= 0 && y < r&& x >= 0 && x < c && board[y][x] != '*');
}

int main() {
    int tc; cin >> tc;
    for (int test = 0; test < tc; test++) {
        
        int ans = 0;
        int n, m;
        cin >> n >> m;
        board.resize(n + 2, vector<char>(m + 2, '.'));

        for (int r = 1; r <= n; r++) {
            string inp;
            cin >> inp;
            for (int c = 1; c <= m; c++) {
                board[r][c] = inp[c-1];
            }
        }
        string keystring;
        cin >> keystring;
        for (size_t i = 0; i < keystring.length(); i++) {
            if (keystring[i] == '0')
                break;

            keys[keystring[i] - 'a'] = true;
        }

        queue<pair<int, int>> q;
        queue<pair<int, int>> locks[26];
        q.push(make_pair(0, 0));
        visited[0][0] = true;

        while (!q.empty()) {
            auto cur = q.front(); q.pop();
            int y = cur.first;
            int x = cur.second;

            for (int d = 0; d < 4; d++) {
                int dy = y + dir_y[d];
                int dx = x + dir_x[d];

                if (isValid(dy, dx, n + 2 , m + 2) && visited[dy][dx] == 0) {
                    //is key
                    if (board[dy][dx] >= 'a' && board[dy][dx] <= 'z') {
                        int keyidx = board[dy][dx] - 'a';
                        if (keys[keyidx] == false) {
                            keys[keyidx] = true;
                            while (!locks[keyidx].empty()) {
                                q.push(locks[keyidx].front());
                                visited[locks[keyidx].front().first][locks[keyidx].front().second] = 1;
                                locks[keyidx].pop();
                            }
                        }
                        q.push({ dy,dx });
                        visited[dy][dx] = 1;
                    }

                    //is door
                    if (board[dy][dx] >= 'A' && board[dy][dx] <= 'Z') {
                        int keyidx = board[dy][dx] - 'A';
                        if (keys[keyidx] == true) {
                            q.push({ dy,dx });
                            visited[dy][dx] = 1;
                        }
                        else {
                            locks[keyidx].push({dy, dx });
                        }
                    }

                    //'. or etc'
                    else {
                        q.push({ dy,dx });
                        visited[dy][dx] = 1;
                        if (board[dy][dx] == '$') {
                            board[dy][dx] = '.';
                            ans++;
                        }

                    }
                }
            }

        }
        cout << ans << endl;
        board.clear();
        memset(visited, 0, sizeof(visited));
        memset(keys, 0, sizeof(keys));
    }
    return 0;
}

