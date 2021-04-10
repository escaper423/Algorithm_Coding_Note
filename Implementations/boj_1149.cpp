#include <iostream>
#include <vector>

#define MAX 1010

using namespace std;

vector<vector<int>> d(3, vector<int>(1000,1000000));
vector<vector<int>> costs(3, vector<int>(1000, 0));

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int r, g, b;
		cin >> r >> g >> b;
		costs[0][i] = r;
		costs[1][i] = g;
		costs[2][i] = b;
	}

	d[0][0] = costs[0][0];
	d[1][0] = costs[1][0];
	d[2][0] = costs[2][0];

	for (int i = 1; i < n; i++) {
		d[0][i] = min(d[0][i], min(d[1][i - 1], d[2][i - 1]) + costs[0][i]);
		d[1][i] = min(d[1][i], min(d[0][i - 1], d[2][i - 1]) + costs[1][i]);
		d[2][i] = min(d[2][i], min(d[0][i - 1], d[1][i - 1]) + costs[2][i]);
	}

	cout << min(d[0][n - 1], min(d[1][n - 1], d[2][n - 1]));
	return 0;
}