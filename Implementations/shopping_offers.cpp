#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
//problem URL : https://leetcode.com/problems/shopping-offers/
using namespace std;

int getRawPrice(vector<int>& price, vector<int>& needs)
{
	int res = 0;
	for (int i = 0; i < needs.size(); i++)
		res += needs[i] * price[i];
	return res;
}

int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
	//get total price without any offer
	int total_price = getRawPrice(price, needs);

	//get offered prices
	for (auto &s : special)
	{
		//tmp = cloned array for current needs to recursion.
		vector<int> tmp(needs);
		bool isEnd = true;
		for (int i = 0; i < tmp.size(); i++)
		{
			//cout << tmp[i] << "-" << s[i] << " "  ;
			int diff = tmp[i] - s[i];
			if (diff < 0)
			{
				isEnd = false;
				break;
			}
			tmp[i] -= s[i];
		}
		//if the offer is valid, then compare the cost from getRawPrice to offered price
		if (isEnd)
			total_price = min(total_price, s.back() + shoppingOffers(price, special, tmp));
	}
	return total_price;
}

int main()
{
	system("pause");
	return 0;
}

