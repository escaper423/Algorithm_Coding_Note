#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
//problem URL : https://leetcode.com/problems/trapping-rain-water/submissions/
using namespace std;

//naive dp solution
int trap(vector<int>& height) {
	vector<int> d(height.size(), 0);
	int res = 0;
	int cur_max = 0;
	for (int i = 0; i < height.size(); i++)
	{
		if (height[i] > cur_max)
			cur_max = height[i];

		d[i] = cur_max;
	}

	cur_max = 0;
	for (int i = height.size() - 1; i >= 0; i--)
	{
		if (height[i] > cur_max)
			cur_max = height[i];

		d[i] = min(d[i], cur_max);
	}

	for (int i = 0; i < height.size(); i++)
	{
		res += (d[i] - height[i]);
	}

	return res;
}

int main()
{
	vector<int> h;
	string s;
	getline(cin, s);
	stringstream ss(s);
	while (getline(ss, s, ' '))
		h.push_back(stoi(s));
	cout << trap(h);
	return 0;
}
