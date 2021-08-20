#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, s;
	vector<int> arr;

	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		arr.push_back(tmp);
	}
	cin >> s;

		for (int start = 0; start < n && s; start++) {
			int mx = arr[start];
			int idx = -1;

			for (int i = start, k = 0; i < n && k <= s; i++, k++) {
				if (mx < arr[i]) {
					mx = arr[i];
					idx = i;
				}
			}
			
			if (idx == -1)
				continue;

			while (idx > start && s > 0) {
				swap(arr[idx], arr[idx - 1]);
				idx--; s--;
			}

			if (s == 0)
				break;
		}


	for (const auto& it : arr) {
		cout << it << " ";
	}

	return 0;
}
