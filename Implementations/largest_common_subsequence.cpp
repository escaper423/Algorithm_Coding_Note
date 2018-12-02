#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

vector<string> split_string(string);
///Some changes
// Complete the longestCommonSubsequence function below.
vector<int> longestCommonSubsequence(vector<int> a, vector<int> b) {
	int as = a.size();
	int bs = b.size();
	vector<vector<int>> D(bs +1, vector<int>(as+1,0));
	vector<int> res;
	for (int i = 1; i <= bs; i++)
	{
		for (int k = 1; k <= as; k++)
		{
			if (a[k - 1] == b[i - 1])
				D[i][k] = D[i - 1][k - 1] + 1;
			else
				D[i][k] = max(D[i - 1][k], D[i][k - 1]);
		}
	}

	int i = bs;
	int k = as;
	while (i > 0 && k > 0)
	{
		if (D[i - 1][k] == D[i][k])
			i--;
		else if (D[i][k - 1] == D[i][k])
			k--;
		else
		{
			res.push_back(a[k - 1]);
			i--;
			k--;
		}
	}
	reverse(res.begin(), res.end());
	return res;
}

int main()
{
	string nm_temp;
	getline(cin, nm_temp);

	vector<string> nm = split_string(nm_temp);

	int n = stoi(nm[0]);

	int m = stoi(nm[1]);

	string a_temp_temp;
	getline(cin, a_temp_temp);

	vector<string> a_temp = split_string(a_temp_temp);

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		int a_item = stoi(a_temp[i]);
		a[i] = a_item;
	}

	string b_temp_temp;
	getline(cin, b_temp_temp);

	vector<string> b_temp = split_string(b_temp_temp);

	vector<int> b(m);
	for (int i = 0; i < m; i++) {
		int b_item = stoi(b_temp[i]);
		b[i] = b_item;
	}

	vector<int> result = longestCommonSubsequence(a, b);

	for (int i = 0; i < result.size(); i++) {
		cout << result[i];

		if (i != result.size() - 1) {
			cout << " ";
		}
	}

	cout << "\n";

	return 0;
}

vector<string> split_string(string input_string) {
	string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
		return x == y && x == ' ';
	});

	input_string.erase(new_end, input_string.end());

	while (input_string[input_string.length() - 1] == ' ') {
		input_string.pop_back();
	}

	vector<string> splits;
	char delimiter = ' ';

	size_t i = 0;
	size_t pos = input_string.find(delimiter);

	while (pos != string::npos) {
		splits.push_back(input_string.substr(i, pos - i));

		i = pos + 1;
		pos = input_string.find(delimiter, i);
	}

	splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

	return splits;
}