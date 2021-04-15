#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
//problem URL : https://leetcode.com/problems/target-sum/
using namespace std;
static int cnt = 1;
int pow(int rep)
{
	return 1 << rep;
}
//Bitmasking variant
//can get accept but very slow
int findTargetSumWays(vector<int>& nums, int S) {
	int res = 0;
	int total_sum = 0;
	for (auto &it : nums)
		total_sum += it;

	for (int i = 0; i < pow(nums.size()); i++)
	{
		int current_sum = total_sum;
		for (int k = 0; k < nums.size(); k++)
		{
			if ((1 << k) & i)
			{
				current_sum -= (nums[k] << 1);
			}
		}
		if (current_sum == S)
			res++;
	}
	return res;
}

/* DFS variant
int dfs(vector<int>&nums, int idx, int sum, int S)
{
	if (idx == nums.size())
		return S == sum;

	int res = dfs(nums, idx + 1, sum - nums[idx], S) + dfs(nums, idx + 1, sum + nums[idx], S);
	return res;
}

int findTargetSumWays(vector<int>& nums, int S) {
	return dfs(nums, 0, 0, S);
}
*/

/* using hashmap
int findTargetSumWays(vector<int>& nums, int S) {
	unordered_map <int, int> m;
	if (nums.size() == 0) return 0;

	m[0] = 1;
	for (int i = 0; i < nums.size(); i++)
	{
		unordered_map<int, int> t;
		for (auto &c : m)
		{
			t[c.first + nums[i]] += c.second;
			t[c.first - nums[i]] += c.second;
		}
		m = t;
	}
	return m[S];
}
*/
int main()
{	
	vector<int> inp = { 1,1,1,1,1 };
	int S = 3;
	cout << findTargetSumWays(inp, S);
	return 0;
}

