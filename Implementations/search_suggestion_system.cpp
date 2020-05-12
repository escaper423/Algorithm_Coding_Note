#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

//problem URL : https://leetcode.com/problems/search-suggestions-system/	

using namespace std;

vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
	sort(products.begin(), products.end());
	vector<vector<string>> res(searchWord.size());

	string to_search("");

	for (int i = 0; i < searchWord.size(); i++) {
		to_search += searchWord.substr(i, 1);
		int matches = 0;

		for (auto &p : products) {
			if (!p.compare(0, to_search.length(), to_search) && matches < 3) {
				matches += 1;
				res[i].push_back(p);
			}
		}
	}
	return res;
}

int main() {
	vector<string> products;
	string searchWord;
	int nProducts;
	cin >> nProducts;
	for (int i = 0; i < nProducts; i++) {
		string token;
		cin >> token;
		products.push_back(token);
	}
	cin >> searchWord;
	auto res = suggestedProducts(products, searchWord);
	for (int i = 0; i < res.size(); i++) {
		for (int k = 0; k < res[i].size(); k++) {
			cout << res[i][k] << " ";
		}
		cout << endl;
	}
	return 0;
}