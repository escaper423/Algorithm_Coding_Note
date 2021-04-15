#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
//problem URL : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
using namespace std;

int maxProfit(vector<int>& prices, int fee) {
	int not_owned = 0;
	int owned = -prices[0];

	for (int i = 1; i < prices.size(); i++)
	{
		not_owned = max(owned + (prices[i] - fee), not_owned);
		owned = max(not_owned - prices[i], owned);
	}
	return not_owned;
}

int main()
{
	vector<int> prices = { 1, 3, 2, 8, 4, 9 };
	int fee;
	cin >> fee;
	maxProfit(prices, fee);
	system("pause");
	return 0;
}

