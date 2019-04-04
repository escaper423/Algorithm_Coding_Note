#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <stack>
#include <unordered_map>
//problem URL : https://leetcode.com/problems/coin-change/
using namespace std;

int coinChange(vector<int>& coins, int amount) {
	if (amount == 0)
		return 0;
	if (coins.size() == 0)
		return -1;
	if (coins.size() == 1)
		return amount % coins[0] == 0 ? amount / coins[0] : -1;

	vector<int> d(amount + 1, INT_MAX);
	d[0] = 0;
	for (int a = 0; a < coins.size(); a++)
	{
		for (int i = 1; i <= amount; i++)
		{
			if (i >= coins[a])
			{
				d[i] = min(d[i], d[i - coins[a]] != INT_MAX ? d[i - coins[a]] + 1 : INT_MAX);
			}
		}
	}
	return d[amount] == INT_MAX ? -1 : d[amount];
}


int main()
{
	int t;
	cin >> t;
	int n;
	cin >> n;
	vector<int> coins(n);
	for (int i = 0; i < n; i++)
	{
		cin >> coins[i];
	}
	cout << coinChange(coins, t);
	return 0;
}
