#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <stack>
#include <unordered_map>
//problem URL : https://leetcode.com/problems/push-dominoes/
using namespace std;

void pushLeft(int i, string &s)
{
	while (i >= 0 && s[i] != 'L')
		s[i--] = 'L';
}

void pushRight(int i, string &s)
{
	while (i < s.size() && s[i] != 'R')
		s[i++] = 'R';
}

void pushRL(int i, int j, string &s)
{
	while (i < j)
	{
		s[i++] = 'R';
		s[j--] = 'L';
	}
}
string pushDominoes(string dominoes) {
	stack<pair<int, char>> stac;
	int n = dominoes.size();
	string s(dominoes);
	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'L' || s[i] == 'R')
			stac.push({ i,s[i] });
	}

	while (!stac.empty())
	{
		int cur_idx = stac.top().first;
		char cur_char = stac.top().second;
		stac.pop();
		if (cur_char == 'R')
			pushRight(cur_idx + 1, s);
		else
		{
			if (stac.empty())
			{
				pushLeft(cur_idx - 1, s);
				break;
			}
			int second_idx = stac.top().first;
			char second_char = stac.top().second;

			if (second_char == 'R')
			{
				pushRL(second_idx + 1, cur_idx - 1, s);
				stac.pop();
			}
			else
				pushLeft(cur_idx - 1, s);
		}
	}
	return s;
}

int main()
{
	string s("..LR.L.L.RRLR..LR...LR..LLR..L.RL.R.R..L..R..");
	cout << pushDominoes(s);
	return 0;
}
