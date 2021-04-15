#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

//problem URL : https://leetcode.com/problems/merge-intervals/


vector<vector<int>> merge(vector<vector<int>>& intervals) {
	int n = intervals.size();
	vector<vector<int>> res;

	sort(intervals.begin(), intervals.end());

	for (int i = 0; i < n; i++) {
		int s = intervals[i][0];
		int e = intervals[i][1];

		int k = i + 1;

		while (k < n && (intervals[k][0] <= e)) {
			e = max(e, intervals[k][1]);
			i++; k++;
		}

		vector<int> tmp{ s,e };
		res.push_back(std::move(tmp));
	}
	return res;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	vector<vector<int>> v;

	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		int s, e;
		cin >> s >> e;
		
		v.push_back({ s,e });
	}
	
	auto res = merge(v);
	cout << "[";
	for (auto& node : res) {
		cout << "[" << node[0] << "," << node[1] << "] ";
	}
	cout << "]" << endl;

	return 0;
}
