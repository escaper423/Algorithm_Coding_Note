#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <iomanip>
#include <queue>
#include <chrono>
//problem URL : https://leetcode.com/problems/longest-increasing-subsequence/
#pragma warning(disable:4996)
using namespace std;

int bs(vector<int> &d, int key)
{
	int lo = -1, hi = d.size() - 1;
	while (lo < hi)
	{
		int m = (lo + hi + 1) / 2;
		if (d[m] < key)
			lo = m;
		else
			hi = m - 1;
	}
	return lo + 1;
}
int lengthOfLIS(vector<int>& nums) {
	int n = nums.size();
	if (n == 0) return 0;
	vector<int> d;
	d.push_back(nums[0]);
	for (int i = 1; i < n; i++)
	{
		if (nums[i] > d.back())
			d.push_back(nums[i]);
		else
			d[bs(d, nums[i])] = nums[i];
	}
	return d.size();
}

int main()
{
	vector<int> v{ 10,9,2,5,3,7,101,18 };
	cout << lengthOfLIS(v);
	return 0;
}
