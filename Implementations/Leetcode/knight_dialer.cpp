#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <iomanip>
#include <queue>
#include <chrono>
//problem URL : https://leetcode.com/problems/knight-dialer/
#pragma warning(disable:4996)
using namespace std;

int m = 1000000007;
int pSum(vector<vector<long>> dials, int N)
{
	int res = 0;
	for (int i = 0; i < dials[0].size(); i++)
		res = (res + dials[(N - 1) % 2][i]) % m;
	return res;
}

int knightDialer(int N) {
	vector<vector<long>> dials(2, vector<long>(10, 1));
	for (int i = 0; i < dials[0].size(); i++)
		dials[1][i] = 0;

	for (int i = 1; i < N; i++)
	{
		dials[i % 2][0] = (dials[(i - 1) % 2][4] + dials[(i - 1) % 2][6]) % m;
		dials[i % 2][1] = (dials[(i - 1) % 2][6] + dials[(i - 1) % 2][8]) % m;
		dials[i % 2][2] = (dials[(i - 1) % 2][7] + dials[(i - 1) % 2][9]) % m;
		dials[i % 2][3] = (dials[(i - 1) % 2][4] + dials[(i - 1) % 2][8]) % m;
		dials[i % 2][4] = (dials[(i - 1) % 2][0] + dials[(i - 1) % 2][3] + dials[(i - 1) % 2][9]) % m;
		dials[i % 2][5] = 0;
		dials[i % 2][6] = (dials[(i - 1) % 2][0] + dials[(i - 1) % 2][1] + dials[(i - 1) % 2][7]) % m;
		dials[i % 2][7] = (dials[(i - 1) % 2][2] + dials[(i - 1) % 2][6]) % m;
		dials[i % 2][8] = (dials[(i - 1) % 2][1] + dials[(i - 1) % 2][3]) % m;
		dials[i % 2][9] = (dials[(i - 1) % 2][4] + dials[(i - 1) % 2][2]) % m;

	}
	return pSum(dials, N);
}

int main()
{
	int n;
	cin >> n;
	cout << knightDialer(n);
	return 0;
}
