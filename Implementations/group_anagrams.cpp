#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>

//problem URL : https://leetcode.com/problems/group-anagrams/

using namespace std;
unordered_map<string, vector<string>> m;

vector<vector<string>> groupAnagrams(vector<string>&& strs) {
	vector<vector<string>> res;
	for (auto& s : strs) {
		string str(s);
		sort(str.begin(), str.end());
		m[str].push_back(s);
	}

	for (auto& it : m) {
		res.push_back(it.second);
	}
	return res;
}

int main() {
	vector<string> v;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string tok;
		cin >> tok;
		v.push_back(std::move(tok));
	}

	vector<vector<string>> ans = groupAnagrams(std::move(v));
	for (auto& a : ans) {
		cout << "[ ";
		for (auto& n : a) {
			cout << n << " ";
		}
		cout << "]" << endl;
	}

	return 0;
}