#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <iomanip>
#include <queue>
#include <chrono>
#include <unordered_set>
//problem URL : https://leetcode.com/problems/minesweeper/
#pragma warning(disable:4996)
using namespace std;

int dir_x[8] = { 0,1,1,1,0,-1,-1,-1 };
int dir_y[8] = { -1,-1,0,1,1,1,0,-1 };

void dfs(vector<vector<char>> &board, int y, int x)
{
	if (y < 0 || x < 0 || x >= board[0].size() || y >= board.size())
		return;

	if (board[y][x] == 'M')
	{
		board[y][x] = 'X';
		return;
	}

	else if (board[y][x] == 'E')
	{
		int cnt = 0;
		for (int i = 0; i < 8; i++)
		{
			int ny = y + dir_y[i];
			int nx = x + dir_x[i];
			if (ny >= 0 && nx >= 0 && ny < board.size() && nx < board[0].size() && board[ny][nx] == 'M')
				cnt++;
		}

		if (cnt > 0)
			board[y][x] = cnt + '0';
		else
		{
			board[y][x] = 'B';
			for (int i = 0; i < 8; i++)
			{
				int ny = y + dir_y[i];
				int nx = x + dir_x[i];
				if (ny >= 0 && nx >= 0 && ny < board.size() && nx < board[0].size() && (board[ny][nx] != 'B' || board[ny][nx] != 'X'))
					dfs(board, ny, nx);
			}
		}

	}
}
vector<vector<char>> updateBoard(vector<vector<char>> board, vector<int> click) {
	int y = click[0];
	int x = click[1];
	dfs(board, y, x);
	return board;
}

int main()
{
	vector<vector<char>> board = {  {'E', 'E', 'E', 'E', 'E'},
									{'E', 'E', 'M', 'E', 'E'},
									{'E', 'E', 'E', 'E', 'E'},
									{'E', 'E', 'E', 'E', 'E'} };

	updateBoard(board, { 3,0 });
	for (int i = 0; i < board.size(); i++)
	{
		for (int k = 0; k < board[0].size(); k++)
			cout << board[i][k] << ' ';
		cout << endl;
	}
	return 0;
}
