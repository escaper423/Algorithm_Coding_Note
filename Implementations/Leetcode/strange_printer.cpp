#include <iostream>
#include <vector>
#include <climits>

using namespace std;

//problem URL : https://leetcode.com/problems/strange-printer/

int strangePrinter(string s) {
	int n = s.length();
	if (n == 0)
		return 0;

	vector<vector<int>> d(n, vector<int>(n, 0));

	char lastChar = {};
	string str = "";
	for (int i = 0; i < n; i++) {
		if (lastChar != s[i])
			str = str + s[i];

		lastChar = s[i];
	}

	for (int i = 0; i < n; i++) {
		d[i][i] = 1;

		if (i < n - 1)
			d[i][i + 1] = 2;
	}

	n = str.length();

	for (int len = 2; len < n; len++) {
		for (int start = 0; start + len < n; start++) {
			d[start][start + len] = len + 1;
			for (int k = 0; k < len; k++) {
				int tmp = d[start][start + k] + d[start + k + 1][start + len];

				d[start][start + len] = min(d[start][start + len],
					(str[start + k] == str[start + len]) ? tmp - 1 : tmp);
			}
		}
	}
	return d[0][n - 1];
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	string str;
	cin >> str;
	cout << strangePrinter(str);
	return 0;
}
