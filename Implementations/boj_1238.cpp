#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define pii pair<int,int>

using namespace std;

vector<vector<pii>> g;
vector<int> d;


int dijkstra(int start, int end) {
	d[start] = 0;

	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({ 0,start });
	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();
		int u = cur.second;
		for (auto& it : g[u]) {
			int v = it.second;
			int cost = it.first;
			if (d[v] > d[u] + cost) {
				d[v] = d[u] + cost;
				pq.push(it);
			}
		}
	}

	return d[end];
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int maxCost = 0;
	int n, e, goal;
	cin >> n >> e >> goal;

	g.resize(n + 1);

	for (int i = 0; i < e; i++) {
		int u, v, cost;
		cin >> u >> v >> cost;
		
		g[u].push_back({ cost,v });
	}

	for (int i = 1; i <= n; i++) {
		d.clear();
		d.resize(n + 1, 0x3f3f3f3f);
		int travelCost = dijkstra(i, goal);
		d.clear();
		d.resize(n + 1, 0x3f3f3f3f);
		int returnCost = dijkstra(goal, i);

		if (travelCost + returnCost > maxCost) {
			maxCost = travelCost + returnCost;
		}
		
	}
	cout << maxCost;
	
	return 0;
}
