#include <iostream>
#include <string>
#include <algorithm>

//problem URL : https://leetcode.com/problems/custom-sort-string/

using namespace std;

int findIndex(char c, string S) {
	auto i = find(S.begin(), S.end(), c);
	if (i == S.end())
		return S.length();
	else {
		return distance(S.begin(), i);
	}
}

string customSortString(string S, string T) {
	string res = T;
	sort(res.begin(), res.end(),
		[&S](char s1, char s2) -> int {
		return findIndex(s1, S) < findIndex(s2, S);
	});
	return res;
}

int main() {
	string S, T;
	cin >> S >> T;
	cout << customSortString(S, T);
	return 0;
}