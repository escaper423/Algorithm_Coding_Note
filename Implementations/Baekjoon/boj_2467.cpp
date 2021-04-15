#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> l;

int res;
int re, rs;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	cin >> n;
	l.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> l[i];
	}
	sort(l.begin(), l.end());

	int s = 0, e = n - 1;
	res = abs(l[s] + l[e]);
	rs = l[s];
	re = l[e];

	while (s < e) {
		int tmp = l[s] + l[e];
		//cout << "Tmp: " << tmp << " s: " << s << " e: " << e <<endl;
		if (res > abs(tmp)) {
			res = abs(tmp);
			rs = l[s]; re = l[e];
		}

		if (tmp > 0) {
			e--;
		}
		else {
			s++;
		}
	}

	cout << rs << " " << re;
	return 0;
}
