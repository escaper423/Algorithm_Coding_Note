#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int checkMaxRight(int s, vector<int>& accu) {
	int res = 0;
	for (int i = s; i < accu.size(); i++) {
		if (accu[i] > res)
			res = accu[i];
	}
	return res;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int h, w;
	cin >> h >> w;
	int res = 0;
	int mx = 0;
	vector<int> accu(w);
	for (int i = 0; i < w; i++) {
		cin >> accu[i];
	}

	for (int i = 0; i < w; i++) {
		mx = max(mx, accu[i]);
		int rmx = checkMaxRight(i + 1, accu);
		int h = min(mx, rmx);
		if (h > accu[i]) {
			res += (h - accu[i]);
		}
	}
	cout << res;
	return 0;
}

//another solution
/*
#include <iostream>
#include <vector>
#include <stack>

using namespace std;
int accu[500] = { 0 };
int d[500] = { 0 };

int main()
{
	int res = 0;
	int h, w;
	cin >> h >> w;

	for (int i = 0; i < w; i++) {
		cin >> accu[i];
	}

	int lmax = 0;
	for (int i = 0; i < w; i++) {
		lmax = max(lmax, accu[i]);
		d[i] = lmax;
	}

	int rmax = 0;
	for (int i = w - 1; i >= 0; --i) {
		rmax = max(rmax, accu[i]);
		d[i] = min(d[i], rmax);
	}

	for (int i = 0; i < w; i++) {
		if (d[i] > accu[i])
			res += d[i] - accu[i];
	}
	cout << res;
	return 0;
//}*/
