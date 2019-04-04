#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <iomanip>
#include <queue>
#include <chrono>
#include <unordered_set>
//problem URL : https://leetcode.com/problems/maximum-product-subarray/
#pragma warning(disable:4996)
using namespace std;

int maxProduct(vector<int> nums) {
	int f_mx = nums[0], f_mn = nums[0];
	int mx = nums[0], mn = nums[0];
	for (int i = 1; i < nums.size(); i++)
	{
		int tmn = mn;
		mn = min(min(mn * nums[i], mx * nums[i]), nums[i]);
		mx = max(max(mx * nums[i], tmn * nums[i]), nums[i]);

		if (f_mx < mx)
			f_mx = mx;

		if (f_mn > mn)
			f_mn = mn;
	}
	return max(f_mx, f_mn);
}
int main()
{
	cout << maxProduct({ 2,3,-2,4 });
	return 0;
}
