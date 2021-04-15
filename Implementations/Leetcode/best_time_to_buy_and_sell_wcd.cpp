#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <stack>
#include <unordered_map>
//problem URL : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
using namespace std;

int maxProfit(vector<int>& prices) {
	if (prices.size() <= 1)
		return 0;
	int owned = max(-prices[0], -prices[1]);
	int not_owned = max(0, -prices[0] + prices[1]);
	int not_owned2 = 0;
	for (int i = 2; i < prices.size(); i++)
	{
		int tmp = not_owned;
		not_owned = max(not_owned, owned + prices[i]);
		owned = max(owned, not_owned2 - prices[i]);
		not_owned2 = tmp;
	}
	return not_owned;
}

int main()
{
	vector<int> v{ 17,221,33,1,121,55,14,41,3,23,13,23,134,51,32,24,414,};
	cout << maxProfit(v);
	return 0;
}
