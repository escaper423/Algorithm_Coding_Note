#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <Windows.h>
#include <unordered_map>

//problem URL : https://leetcode.com/problems/longest-string-chain/

using namespace std;

unordered_map<string, int> m;

int getChain(string str) {
	if (str.length() == 0)
		return 1;

	for (int i = 0; i < str.length(); i++) {
		string cur = str;
		cur.erase(i, 1);
		if (m.find(cur) != m.end())
			return m[cur] = getChain(cur) + 1;
	}
	return 1;

}
int longestStrChain(vector<string>& words) {
	int res = 0;

	for (auto &it : words) {
		m[it] += 1;
	}

	for (auto &str : words) {
		res = max(res, getChain(str));
	}
	return res;
}
4
int main() {
	vector<string> words;
	int n; 
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		words.push_back(s);
	}
	cout << longestStrChain(words) << endl; 
	system("pause");
	return 0;
}
