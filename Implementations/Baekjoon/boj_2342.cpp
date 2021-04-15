#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;

vector<int> v;
//1 up 2 left 3 down 4 right
int costs[5][5] = {
	{0,2,2,2,2},
	{2,1,3,4,3},
	{2,3,1,3,4},
	{2,4,3,1,3},
	{2,3,4,3,1}
};

int d[2][5][5];

int res = 5000000;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	while (1) {
		int num;
		cin >> num;
		if (num == 0)
			break;

		v.push_back(num);
	}

	int n = v.size();
	memset(d, 5000000, sizeof(d));

	int step = 1;
	d[0][0][0] = 0;

	while (n) {
		for (int l = 0; l < 5; l++) {
			for (int r = 0; r < 5; r++) {
				int target = v[step - 1];

				if (step > 1 && l == r)
					continue;

				d[step%2][target][r] = min(d[step%2][target][r], d[(step - 1)%2][l][r] + costs[l][target]);
				d[step%2][l][target] = min(d[step%2][l][target], d[(step - 1)%2][l][r] + costs[r][target]);
			}
		}
		n--;
		step++;
	}

	for (int i = 0; i < 5; i++)
		for (int k = 0; k < 5; k++)
			res = min(res, d[(step - 1)%2][i][k]);

	cout << res;
	return 0;
}