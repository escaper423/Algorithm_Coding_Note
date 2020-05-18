#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>

//problem URL : https://leetcode.com/problems/word-subsets/

using namespace std;

vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
	vector<string> res;

	vector<int> maxFreqMap(26, 0);

	for (const auto& str : B) {
		vector<int> freq(26, 0);
		for (auto& s : str) {
			freq[s - 'a']++;
		}

		for (int i = 0; i < 26; i++) {
			maxFreqMap[i] = max(maxFreqMap[i], freq[i]);
		}
	}

	for (const auto& str : A) {
		vector<int> charMap(26, 0);
		bool isSubstr = true;

		for (const auto& s : str) {
			charMap[s - 'a']++;
		}

		for (int i = 0; i < 26; i++) {
			int d = charMap[i] - maxFreqMap[i];
			if (d < 0) {
				isSubstr = false;
				break;
			}
		}
		if (isSubstr)
			res.push_back(str);
	}
	return res;
}

int main() {
	int la, lb;
	vector<string> A;
	vector<string> B;
	cin >> la;

	for (int i = 0; i < la; i++) {
		string inp;
		cin >> inp;
		A.push_back(inp);
	}
	cin >> lb;
	for (int i = 0; i < lb; i++) {
		string inp;
		cin >> inp;
		B.push_back(inp);
	}

	auto res = wordSubsets(A, B);
	for (auto& it : res)
		cout << it << " ";

	return 0;
}