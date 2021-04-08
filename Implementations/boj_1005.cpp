#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int tc;
	cin >> tc;
	for (int t = 0; t < tc; t++) {
		int n, k, goal;
		cin >> n >> k;

		vector<vector<int>> g(n+1);
		int costs[1001] = { 0 };
		int max_cost[1001] = { 0 };
		int inc[1001] = { 0 };

		for (int i = 1; i <= n; i++)
			cin >> costs[i];

		for (int i = 1; i <= k; i++) {
			int u, v; cin >> u >> v;
			g[u].emplace_back(v);
			inc[v]++;
		}
		cin >> goal;

		queue<int> q;

		for (int i = 1; i <= n; i++) {
			if (inc[i] == 0)
				q.push(i);
		}

		while (!q.empty()) {
			auto cur = q.front(); q.pop();

			int cur_node = cur;

			if (cur == goal) {
				break; 
			}

			for (auto& v : g[cur_node]) {
				max_cost[v] = max(max_cost[v],max_cost[cur_node] + costs[cur_node]);

				if (--inc[v] == 0) {
					q.push(v);
				}
			}
		}
		cout << max_cost[goal] + costs[goal] << endl;
	}
	return 0;
}