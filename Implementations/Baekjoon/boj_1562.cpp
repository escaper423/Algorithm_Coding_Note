#include <iostream>

#define MOD 1000000000
int d[100][10][1 << 10] = { 0 };
using namespace std;

int n;

int countBits(int n) {
	int cnt = 0;
	while (n) {
		n &= (n - 1);
		cnt++;
	}
	return cnt;
}

int doSomething(int len, int fig, int stat) {

	if (len == n) {
		return (countBits(stat) == 10)? 1 : 0;
	}

	if (d[len][fig][stat])
		return d[len][fig][stat];

	if (fig == 0) {
		d[len][fig][stat] += doSomething(len + 1, fig + 1, stat | (1 << (fig + 1)));
		return d[len][fig][stat] %= MOD;
	}
		
	else if (fig == 9) {
		d[len][fig][stat] += doSomething(len + 1, fig - 1, stat | (1 << (fig - 1)));
		return d[len][fig][stat] %= MOD;
	}
		
	else {
		d[len][fig][stat] += (doSomething(len + 1, fig - 1, stat | (1 << (fig - 1))) + doSomething(len + 1, fig + 1, stat | (1 << (fig +1))) );
		return d[len][fig][stat] %= MOD;
	}
		

}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	cin >> n;
	int res = 0;

	for (int i = 1; i < 10; i++) {
		res += doSomething(1,i,1 << i);
		res %= MOD;
	}

	cout << res;

	return 0;
}