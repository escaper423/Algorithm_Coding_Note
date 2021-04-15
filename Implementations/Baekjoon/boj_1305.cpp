#include <iostream>
#include <vector>
using namespace std;

vector<int> lps;

void makeLpsArray(string &pat) {
	int N = pat.length();
	int len = 0;
	int i = 1;
	lps[0] = 0;

	while (i < N) {
		if (pat[len] == pat[i]) {
			len++;
			lps[i] = len;
			i++;
		}
		else {
			if (len > 0) {
				len = lps[len - 1];
			}
			else {
				lps[i] = 0;
				i++;
			}
		}
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	string pat;
	cin >> n >> pat;
	lps.resize(n);

	makeLpsArray(pat);
	cout << n - lps[n - 1];
	return 0;
}