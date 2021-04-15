#include <vector>
#include <iostream>

using namespace std;
//Problem URL: https://leetcode.com/problems/partition-equal-subset-sum/
//Reference: https://leetcode.com/problems/partition-equal-subset-sum/discuss/641257/DP-100-space-solution-wvideo-whiteboard-explanation

bool canPartition(vector<int>& nums) {
	int N = nums.size();

	if (N == 0)
		return false;
	int sum = 0;
	for (auto &it : nums)
		sum += it;

	if (sum % 2 != 0)
		return false;

	sum /= 2;

	vector<bool> dp(sum + 1, false);
	dp[0] = true;

	for (auto &it : nums) {
		for (int i = sum; i >= it; i--) {
			dp[i] = dp[i] || dp[i - it];
		}
	}
	return dp[sum];
}


int main() {
	vector<int> nums;
	int n;
	cin >> n;
	nums.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	//false: 0, true = 1
	cout << canPartition(nums);
	return 0;
}
