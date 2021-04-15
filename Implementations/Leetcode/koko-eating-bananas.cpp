#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <stack>
#include <unordered_map>
//problem URL : https://leetcode.com/problems/koko-eating-bananas/
//refereced dfs solution
using namespace std;

int getNeededTime(vector<int>& piles, int k) {
	int res = 0;
	int n = piles.size();

	for (int i = 0; i < n; i++) {
		int to_add = piles[i] / k;
		if (to_add == 0) {
			to_add = 1;
		}
		else if (piles[i] % k != 0) {
			to_add++;
		}
		res += to_add;
	}
	return res;
}

int minEatingSpeed(vector<int>& piles, int h) {
	sort(piles.begin(), piles.end());

	int l = 1;
	int r = 1e9;
	int k;
	int res = 0;

	while (l <= r) {
		k = l + (r - l) / 2;
		if (getNeededTime(piles, k) > h) {
			l = k + 1;
		}
		else if (getNeededTime(piles, k) <= h) {
			res = k;
			r = k - 1;
		}
	}
	return res;
}

int main{
	vector<int> p;
	int h;
	
	
	return 0;
	
}