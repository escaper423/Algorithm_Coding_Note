#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <iomanip>
#include <queue>
#include <chrono>
#include <unordered_set>
//problem URL : https://leetcode.com/problems/word-break/
#pragma warning(disable:4996)
using namespace std;

bool wordBreak(string s, vector<string> wordDict) {
	vector<bool> d(s.size() + 1, false);
	unordered_set<string> m(wordDict.begin(), wordDict.end());
	d[0] = true;

	for (int i = 1; i <= s.size(); i++)
	{
		for (int k = 0; k < i; k++)
		{
			if (d[k] == true && m.find(s.substr(k, i - k)) != m.end())
			{
				d[i] = true;
				break;
			}
		}
	}
	return d[s.size()];
}

int main()
{
	cout << wordBreak("leetcode", {"leet","code"});
	return 0;
}
