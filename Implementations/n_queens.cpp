#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <stack>
#include <unordered_map>
//problem URL : https://leetcode.com/problems/n-queens/
using namespace std;

bool isSafe(int r, int c, vector<string> &board)
{
	for (int col = 0; col < c; col++)
	{
		if (board[r][col] == 'Q')
			return false;
	}

	int i = r - 1, j = c - 1;
	while (i >= 0 && j >= 0)
	{
		if (board[i--][j--] == 'Q')
			return false;
	}

	i = r + 1, j = c - 1;
	while (i < board.size() && j >= 0)
	{
		if (board[i++][j--] == 'Q')
			return false;
	}
	return true;
}

void nq(int c, vector<string> &board, vector<vector<string>> &res)
{
	if (c == board.size())
	{
		res.push_back(board);
		return;
	}

	for (int row = 0; row < board.size(); row++)
	{
		if (isSafe(row, c, board) == true)
		{
			board[row][c] = 'Q';
			nq(c + 1, board, res);
			board[row][c] = '.';
		}
	}
}
vector<vector<string>> solveNQueens(int n) {
	vector<vector<string>> res;
	vector<string> board(n, string(n, '.'));
	nq(0, board, res);
	return res;
}

int main()
{
	int c;
	cin >> c;
	vector<vector<string>> q = solveNQueens(c);
	for (int i = 0; i < q.size(); i++)
	{
		for (auto &it : q[i])
		{
			cout << it;
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}
