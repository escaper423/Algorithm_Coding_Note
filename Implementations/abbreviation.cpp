#include <iostream>
#include <string>
#include <vector>

using namespace std;

int f(string a, string b, vector<vector<int>> &D)
{
	int al = a.length();
	int bl = b.length();
	if (al < bl) return 0;
	else if (al == 0 && bl != 0) return 0;
	else if (a.length() == 0 && b.length() == 0) return 1;
	else if (al != 0 && bl == 0)
	{
		string la("");
		for (auto &it : a)
			la += tolower(it);
		if (!la.compare(a))
			return 1;
		else return 0;
	}
	else if ((a[al - 1] != b[bl - 1]) && isupper(a[al - 1])) return 0;

	
	if (D[al - 1][bl - 1] != -1)
		return D[al - 1][bl - 1];
	else
	{
		if (a[al - 1] == b[bl - 1])
			D[al - 1][bl - 1] = f(a.substr(0, a.length() - 1), b.substr(0, b.length() - 1), D);
		else
		{
			if (toupper(a[al - 1]) == b[bl - 1]) {
				D[al - 1][bl - 1] = f(a.substr(0, a.length() - 1), b, D) ||
					f(a.substr(0, a.length() - 1), b.substr(0, b.length() - 1), D);

			}
			else
				D[al - 1][bl - 1] = f(a.substr(0, a.length() - 1), b, D);
		}
	}
	return D[al - 1][bl - 1];
}
// Complete the abbreviation function below.
string abbreviation(string a, string b) {
	vector<vector<int>> D(a.length(), vector<int>(b.length()));
	for (int i = 0; i < D.size(); i++)
		for (int j = 0; j < D[i].size(); j++)
			D[i][j] = -1;

	if (f(a, b, D))
		return "YES";
	else return "NO";
}

int main()
{
	int q;
	cin >> q;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	for (int q_itr = 0; q_itr < q; q_itr++) {
		string a;
		getline(cin, a);

		string b;
		getline(cin, b);

		string result = abbreviation(a, b);
		cout << result << endl;
	}
	return 0;
}

