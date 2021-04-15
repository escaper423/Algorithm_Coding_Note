#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <iomanip>
#include <queue>
#include <chrono>
#include <unordered_set>
//problem URL : https://leetcode.com/problems/combination-sum-iv/
#pragma warning(disable:4996)
using namespace std;

int combinationHelper(int val, int target, vector<int> nums, vector<int> &d)
{
	if (val == target)
		return 1;
	else if (val > target)
		return 0;

	if (d[val] != -1)
		return d[val];

	int res = 0;
	for (int i = 0; i < nums.size(); i++)
		res += combinationHelper(val + nums[i], target, nums, d);

	return d[val] = res;

}

int combinationSum4(vector<int> nums, int target) {
	vector<int> d(target + 1, -1);
	return combinationHelper(0, target, nums, d);

}

int main()
{
	cout << combinationSum4({ 1,2,3 }, 4);
	return 0;
}
