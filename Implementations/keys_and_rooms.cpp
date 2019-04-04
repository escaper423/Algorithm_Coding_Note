#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <stack>
#include <unordered_map>
//problem URL : https://leetcode.com/problems/keys-and-rooms/
using namespace std;

void dfs(vector<vector<int>>& rooms, vector<bool> &visited, int u)
{
	if (rooms.size() == 0)
		return;

	visited[u] = true;
	if (rooms.size() == 1)
		return;

	for (auto &v : rooms[u])
	{
		if (!visited[v])
			dfs(rooms, visited, v);
	}
}
bool canVisitAllRooms(vector<vector<int>>& rooms) {
	vector<bool> visited(rooms.size(), false);
	dfs(rooms, visited, 0);

	for (int i = 0; i < visited.size(); i++)
		if (!visited[i])
			return false;

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
	cout << (canVisitAllRooms(g) == true)?"true":"false";
	return 0;
}
