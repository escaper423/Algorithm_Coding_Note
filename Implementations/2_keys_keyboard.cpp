#include <iostream>
#include <vector>
//problem URL : https://leetcode.com/problems/2-keys-keyboard/
using namespace std;

int minSteps(int n) {
	vector<int> D(n + 1, 9999);
	D[1] = 0;
	for (int i = 1; i <= n / 2; i++)
	{
		for (int k = i + i; k <= n; k += i)
		{
			if (k == i + i)
				D[k] = D[k - i] + 2;
			else
				D[k] = D[k - i] + 1;
		}
	}
	return D[n];
}

int main()
{
	int n;
	cin >> n;
	minSteps(n);
	return 0;
}
