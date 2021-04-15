#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
//problem URL : https://leetcode.com/problems/maximum-length-of-pair-chain/
using namespace std;

int findLongestChain(vector<vector<int>>& pairs) {
	sort(pairs.begin(), pairs.end(), [](vector<int> a, vector<int> b) {return a[1] < b[1]; });
	int cnt = 1;
	int cur_idx = 0;
	for (int i = 1; i < pairs.size(); i++)
	{
		//can be paired
		if (pairs[cur_idx][1] < pairs[i][0])
		{
			cur_idx = i;
			cnt++;
		}
		else if (pairs[cur_idx][1] >= pairs[i][0] && pairs[cur_idx][1] <= pairs[i][1])
			continue;
		else
			cur_idx = i;
	}
	return cnt;
}

int main()
{

	system("pause");
	return 0;
}

