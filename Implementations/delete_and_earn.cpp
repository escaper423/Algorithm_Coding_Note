#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
//problem URL : https://leetcode.com/problems/delete-and-earn/
using namespace std;

int deleteAndEarn(vector<int>& nums) {
	vector<int> d(10001, 0);

	for (auto &it : nums)
		d[it]++;

	int prev1 = 0, prev2 = 0;
	int tmp;
	for (int i = 1; i <= 10000; i++)
	{
		tmp = prev1;
		prev1 = max(prev1, prev2 + d[i] * i);
		prev2 = tmp;
	}
	return prev1;
}

int main()
{
	vector<int> h;
	string s;
	getline(cin, s);
	stringstream ss(s);
	while (getline(ss, s, ' '))
		h.push_back(stoi(s));
	cout << deleteAndEarn(h);
	return 0;
}
