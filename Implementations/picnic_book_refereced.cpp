#include <iostream>
#include <vector>

using namespace std;

int countPair(int n, vector<bool> taken, vector< vector<int>> areFriend)
{
	int first = -1;
	for (int i = 0; i < n; ++i)
		if (!taken[i])
		{
			first = i;
			break;
		}

	if (first == -1) return 1;
	
	int ret = 0;
	for (int pair_with = first + 1; pair_with < n; ++pair_with)
	{
		if (!taken[pair_with] && areFriend[first][pair_with])
		{
			taken[pair_with] = taken[first] = true;
			ret += countPair(n, taken, areFriend);
			taken[pair_with] = taken[first] = false;
		}
	}
	return ret;
}

int main()
{
	vector<int> prt;
	vector<vector<int>> v;
	int tc;
	cin >> tc;
	for (int tests = 0; tests < tc; tests++)
	{
		int n, m;
		cin >> n >> m;
		v.resize(n, vector<int>(n));

		for (int i = 0; i < m; i++)
		{
			int fst, scd;
			cin >> fst >> scd;
			v[scd][fst] = 1;
			v[fst][scd] = 1;
		}
		vector<bool> taken(n,false);
		prt.push_back( countPair(n,taken,v) );
		v.clear();
	}
	for (auto &it : prt)
		cout << it << endl;
	return 0;
}
