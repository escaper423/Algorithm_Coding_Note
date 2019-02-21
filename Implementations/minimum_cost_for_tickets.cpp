#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
//problem URL : https://leetcode.com/problems/minimum-cost-for-tickets/
using namespace std;

int mincostTickets(vector<int>& days, vector<int>& costs) {
	vector<int> dp(366, INT_MAX);
	dp[0] = 0;
	int d = 0;

	for (int i = 1; i <= days.back(); i++)
	{
		if (i == days[d])
		{
			dp[i] = min(dp[max(0, i - 1)] + costs[0],
				min(dp[max(0, i - 7)] + costs[1], dp[max(0, i - 30)] + costs[2]));
			d++;
		}
		else
			dp[i] = dp[i - 1];
	}
	return dp[days.back()];
}

int main()
{
	vector<int> days;
	vector<int> costs(3);
	string s;
	getline(cin, s);
	stringstream ss(s);
	while (getline(ss, s, ' '))
		days.push_back(stoi(s));
	for (auto &it : costs)
		cin >> it;
	cout << "answer : " << mincostTickets(days, costs);
	return 0;
}

