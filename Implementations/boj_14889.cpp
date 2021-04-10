#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int board[20][20] = { 0 };

int countSet(int i) {
	int res = 0;
	while (i) {
		i &= i - 1;
		res++;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	int ans = 0x3f3f3f3f;
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			cin >> board[i][k];
		}
	}
	
	int mn = (1 << (n >> 1)) - 1;
	int mx = ((1 << n) - 1);

	for (int i = mn; i <= mx; i++) {

		if (countSet(i) != (n >> 1))
			continue;

		vector<int> start;
		vector<int> link;

		for (int k = 0; k < n; k++) {
			if (i & (1 << k))
				start.emplace_back(k);
			else
				link.emplace_back(k);
		}

		int ssum = 0, lsum = 0;
		for (int s = 0; s < start.size() - 1; s++) {
			for (int l = s+1; l < start.size(); l++) {
				int i1 = start[s]; int i2 = start[l];
				int j1 = link[s]; int j2 = link[l];

				ssum += (board[i1][i2] + board[i2][i1]);
				lsum += (board[j1][j2] + board[j2][j1]);
			}
		}

		ans = min(ans, min(abs(lsum - ssum), abs(ssum - lsum)));
	}
	cout << ans;
	return 0;
}