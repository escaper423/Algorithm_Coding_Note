#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <stack>
#include <unordered_map>
//problem URL : https://leetcode.com/problems/is-graph-bipartite/
//refereced dfs solution
using namespace std;
//color = 1,-1
bool colorize(vector<vector<int>> &g, unordered_map<int, int> &color, int v)
{
	for (auto &it : g[v])
	{
		if (color.find(it) == color.end())
		{
			color[it] = -color[v];
			if (!colorize(g, color, it))
				return false;
		}
		else if (color[it] == color[v])
			return false;
	}
	return true;
}

bool isBipartite(vector<vector<int>>& graph) {
	unordered_map<int, int> color;

	for (int i = 0; i < graph.size(); i++)
	{
		if (color.find(i) == color.end())
			color[i] = 1;

		if (!colorize(graph, color, i))
			return false;
	}
	return true;
}

int main()
{
	int n;
	cin >> n;
	vector<vector<int>> g(n, vector<int>());
	for (int i = 0; i < n; i++)
	{
		int num_size;
		cin >> num_size;
		g[i].resize(num_size);
		for (int k = 0; k < num_size; k++)
			cin >> g[i][k];
	}
	cout << (isBipartite(g) == true)?"true":"false";
	return 0;
}
