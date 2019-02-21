#include <iostream>
#include <string>
#include <vector>
//problem URL : https://leetcode.com/problems/longest-palindromic-subsequence/
using namespace std;

int longestPalindromeSubseq(string s) {
	int n = s.length();
	vector<vector<int>> d(n, vector<int>(n));

	for (int i = n - 1; i >= 0; i--)
	{
		d[i][i] = 1;
		for (int j = i + 1; j < n; j++)
		{
			if (s[i] == s[j])
				d[i][j] = d[i + 1][j - 1] + 2;
			else
				d[i][j] = max(d[i + 1][j], d[i][j - 1]);
		}
	}
	return d[0][n - 1];
}

int main()
{
	string s;
	cin >> s;
	longestPalindromeSubseq(s);
	return 0;
}
