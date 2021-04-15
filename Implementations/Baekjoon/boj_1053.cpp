#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

int d[50][50];

int doSomething(string s, int l, int r) {
	if (l >= r)
		return 0;
	if (d[l][r] != -1)
		return d[l][r];

	return d[l][r] = min(doSomething(s, l + 1, r) + 1, min(doSomething(s, l, r - 1) + 1, doSomething(s, l + 1, r - 1) + (s[l] != s[r])));
}
int main()
{	
	string inp;
	cin >> inp;
	int res;

	memset(d, -1, sizeof(d));
	for (int i = 0; i < inp.size(); i++) {
		d[i][i] = 0;
		if (i != inp.size() - 1)
			d[i][i + 1] = (inp[i] == inp[i+1])?0:1;
	}
	res = doSomething(inp,0,inp.length() - 1);
	for (int i = 0; i < inp.size() - 1; i++) {
		for (int k = 1; k < inp.size(); k++) {
			string tmp(inp);
			swap(tmp[i], tmp[k]);
			memset(d, -1, sizeof(d));
			res = min(res,doSomething(tmp, 0 , tmp.length() - 1) + 1);
		}
	}
	cout << res;
	return 0;
}
