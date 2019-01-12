#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int>> cache(101, vector<int>(101, -1));
int wildcard(string w, string s)
{
	if (w.length() == 0)
		return cache[w.length()][s.length()] = s.length() == 0 ? 1 : 0;
	else if (s.length() == 0)
		return cache[w.length()][s.length()] = w[0] == '*' ? wildcard(w.substr(1), s) : 0;

	if (cache[w.length()][s.length()] != -1)
		return cache[w.length()][s.length()];

	if (w[0] == '*')
		cache[w.length()][s.length()] = wildcard(w.substr(1), s) || wildcard(w, s.substr(1));
	else if (w[0] == s[0] || w[0] == '?')
		cache[w.length()][s.length()] = wildcard(w.substr(1), s.substr(1));
	else
		cache[w.length()][s.length()] = 0;

	return cache[w.length()][s.length()];
}


int main()
{	
	vector<string> res;
	vector<string> str;

	int test_case;
	cin >> test_case;
	for (int test_count = 0; test_count < test_case; test_count++)
	{

		string w;
		cin >> w;
		int cnt;
		cin >> cnt;

		for (int strs = 0; strs < cnt; strs++)
		{
			string s;
			cin >> s;
			str.push_back(s);
		}

		for (const auto &it : str)
		{
			if (wildcard(w, it) == 1)
				res.push_back(it);

			for (int i = 0; i < cache.size(); i++)
				for (int k = 0; k < cache[0].size(); k++)
					cache[i][k] = -1;
		}
		sort(res.begin(), res.end());
		for (auto &s : res)
			cout << s << endl;
		str.clear();
		res.clear();
	}
	return 0;
}

