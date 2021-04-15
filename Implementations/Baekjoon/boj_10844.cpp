#include <iostream>
#include <vector>
#include <algorithm>

#define ll long long

using namespace std;

ll d[11][101] = { 0 };

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 1; i < 10; i++) {
		d[i][1] = 1;
	}

	for (int l = 2; l <= n; l++) {
		for (int num = 0; num < 10; num++) {
			if (num == 0)
				d[num][l] = d[num + 1][l - 1];
			else
				d[num][l] = (d[num - 1][l - 1] + d[num + 1][l - 1])%1000000000;
		}
	}

	ll res = 0;
	for (int i = 0; i <= 9; i++) {
		res += (d[i][n] % 1000000000);
		res %= 1000000000;
	}
	cout << res;

	return 0;
}
