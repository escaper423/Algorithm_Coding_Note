#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <Windows.h>
#include <unordered_map>
#include <unordered_set>

//problem URL : https://leetcode.com/problems/number-of-operations-to-make-network-connected/

using namespace std;

unordered_set<int> visited;
int numGroup = -1;

void findNumConnected(vector<vector<int>> &g, int i) {
	visited.insert(i);
	for (auto &it : g[i]) {
		if (visited.find(it) == visited.end()) {
			findNumConnected(g, it);
		}
	}
}

int makeConnected(int n, vector<vector<int>>& connections) {

	int edges = connections.size();

	vector<vector<int>> g(n, vector<int>());
	for (auto &it : connections) {
		g[it[0]].push_back(it[1]);
		g[it[1]].push_back(it[0]);
	}

	for (int i = 0; i < n; i++) {
		if (visited.find(i) == visited.end())
		{
			findNumConnected(g, i);
			numGroup++;
		}
	}

	if (edges >= n - 1)
		return numGroup;
	else
		return -1;

}

int main() {
	vector<vector<int>> c;
	int node_num;
	cin >> node_num;
	int edge_num;
	cin >> edge_num;
	c.resize(edge_num);
	for (int i = 0; i < edge_num; i++) {
		int f, s;
		cin >> f >> s;
		c[i].push_back(f);
		c[i].push_back(s);
	}

	cout << makeConnected(node_num, c) << endl;
	system("pause");
	return 0;
}
