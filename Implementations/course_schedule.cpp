#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <iomanip>
#include <queue>
#include <chrono>
#include <unordered_set>
//problem URL : https://leetcode.com/problems/course-schedule/
#pragma warning(disable:4996)
using namespace std;

enum { White = 0, Grey, Black };
bool dfs(int n, vector<int> &visited, vector<vector<int>> &g)
{
	if (visited[n] == White)
	{
		visited[n] = Grey;
		// g[n][i] = destination node
		for (int i = 0; i < g[n].size(); i++)
		{
			if ((visited[g[n][i]] == White) && dfs(g[n][i], visited, g))
				return true;
			else if (visited[g[n][i]] == Grey)
				return true;
		}
	}
	visited[n] = Black;
	return false;
}

bool canFinish(int numCourses, vector<pair<int, int>> p) {
	vector<int> visited(numCourses, White);
	vector<vector<int>> graph(numCourses, vector<int>());

	for (auto &it : p)
		graph[it.second].push_back(it.first);

	for (int i = 0; i < numCourses; i++)
		if (dfs(i, visited, graph))
			return false;

	return true;

}

int main()
{
	cout << canFinish(2, { {1,0} }) << endl;
	cout << canFinish(2, { {1,0},{0,1} }) << endl;
	return 0;
}
