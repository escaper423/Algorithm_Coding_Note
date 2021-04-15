#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <stack>
#include <unordered_map>
//problem URL : https://leetcode.com/problems/regions-cut-by-slashes/
//referenced two solutions : dfs, union-find
using namespace std;

vector<int> parents;
int Find(int v)
{
	if (parents[v] != v)
		return Find(parents[v]);
	return v;
}

void Union(int v1, int v2)
{
	int x = Find(v1);
	int y = Find(v2);
	parents[x] = y;

}

int regionsBySlashes(vector<string>& grid)
{
	int n = grid.size();
	parents.resize(4 * n * n);

	for (int i = 0; i < parents.size(); i++)
		parents[i] = i;

	//0 north 1 east 2 west 3 south
	for (int r = 0; r < n; r++)
	{
		for (int c = 0; c < n; c++)
		{
			int root = 4 * (n * r + c);
			//'\'
			if (grid[r][c] == ' ')
			{
				Union(root + 0, root + 1);
				Union(root + 1, root + 2);
				Union(root + 2, root + 3);

			}
			//'/'
			else if (grid[r][c] == '/')
			{
				Union(root + 0, root + 2);
				Union(root + 1, root + 3);
			}
			else
			{
				Union(root + 0, root + 1);
				Union(root + 2, root + 3);
			}

			if (r + 1 < n)
				Union(root + 3, (root + 4 * n) + 0);
			if (c + 1 < n)
				Union(root + 1, (root + 4) + 2);

		}

	}
	int res = 0;
	for (int i = 0; i < parents.size(); i++)
	{
		if (Find(parents[i]) == i)
			res++;
	}
	return res;

}
/* DFS Approach
int dir_y[4] = {1,0,0,-1};
int dir_x[4] = {0,1,-1,0};
void visit(vector<vector<int>> &table, int row, int col, int cnt)
{
	if(row < table.size() && row >= 0 && col >= 0 && col < table.size() && table[row][col] == 0)
	{
		table[row][col] = cnt;
		for(int dir = 0; dir < 4; dir++)
		{
			int nextR = row + dir_y[dir];
			int nextC = col + dir_x[dir];
			visit(table,nextR,nextC,cnt);
		}
	}
}

int regionsBySlashes(vector<string>& grid) {
	int n = grid.size();
	vector<vector<int>> table(n * 3, vector<int>(n * 3,0));
	for(int i = 0; i < n; i++)
	{
		for(int k = 0; k < n; k++)
		{
		   if(grid[i][k] == '\\')
		   {
			   table[i * 3][k * 3] = -1;
			   table[i * 3 + 1][k * 3 + 1] = -1;
			   table[i * 3 + 2][k * 3 + 2] = -1;
		   }
			else if (grid[i][k] == '/')
			{
			   table[i * 3][k * 3 + 2] = -1;
			   table[i * 3 + 1][k * 3 + 1] = -1;
			   table[i * 3 + 2][k * 3] = -1;
			}
		}
	}
	int cnt = 0;
	for(int i = 0; i < 3 * n; i++)
	{
		for(int k = 0; k < 3 * n; k++)
		{
		   if(table[i][k] == 0)
		   {
				cnt++;
				visit(table, i, k, cnt);
		   }
		}
	}
	return cnt;
}
*/

int main()
{
	int n;
	cin >> n;
	vector<string>grid(n);
	string s;
	for (int i = 0; i < n; i++)
	{
		getline(cin, s);
		grid.push_back(s);
	}
	regionsBySlashes(grid);
	return 0;
}
