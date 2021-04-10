#include <string>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void printTrace(vector<pair<int, char>>& trace, int cur, string s) {
    if (cur == -1) {
        cout << s << endl;
        return;
    }
    printTrace(trace, trace[cur].first, trace[cur].second + s);
}
void bfs(int N) {
    //first: number
    //second: represented number [0,1]
    queue<int> q;
    q.push(1);
    vector<int> visited(20010, 0);
    visited[1] = 1;
    vector<pair<int, char>> trace(20010);
    trace[1] = { -1,'1' };

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        int p[2] = { 0,1 };
        bool isEnd = false;

        for (auto& d : p) {
            int next = (cur * 10 + d) % N;
            if (!visited[next]) {
                visited[next] = 1;
                trace[next] = { cur,d + '0' };
                q.push(next);
            }
            if (!next)
            {
                isEnd = true;
                break;
            }
        }

        if (isEnd) {
            break;
        }
    }

    printTrace(trace, 0, "");
        
}
int main() {
    int tc;
    cin >> tc;
    for (int i = 0; i < tc; i++) {
        int n;
        cin >> n;
        if (n == 1) {
            cout << n << endl;
            continue;
        }
        bfs(n);
            
    }
    return 0;
}

