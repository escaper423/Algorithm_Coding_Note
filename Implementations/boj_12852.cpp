#include <iostream>

#define pii pair<int,int>

using namespace std;

pii d[1000001];

void printTrace(int n) {
	while (d[n].first != n) {
		cout << n << " ";
		n = d[n].first;
	}
	cout << n;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		d[i].first = 0x3f3f3f3f;
		d[i].second = 0x3f3f3f3f;
	}

	d[1] = { 1,0 };
	for (int i = 2; i <= n; i++) {
		if (i % 3 == 0 && d[i].second > d[i / 3].second + 1) {
			d[i].first = i / 3;
			d[i].second = d[i / 3].second + 1;
		}
			
		if (i % 2 == 0 && d[i].second > d[i / 2].second + 1) {
			d[i].first = i / 2;
			d[i].second = d[i / 2].second + 1;
		}
		
		if (d[i].second > d[i - 1].second) {
			d[i].first = i - 1;
			d[i].second = d[i - 1].second + 1;
		}
	}

	cout << d[n].second << endl;
	printTrace(n);
	return 0;
}