#include <iostream>
#include <vector>
//problem URL : https://leetcode.com/problems/unique-binary-search-trees/
using namespace std;

int numTrees(int n) {
	vector<int> d(n + 1);
	if (n <= 1) return 1;

	d[0] = 1;
	d[1] = 1;
	for (int k = 2; k <= n; k++)
	{
		for (int i = 1; i <= k; i++)
		{
			d[k] += d[i - 1] * d[k - i];
		}
	}
	return d[n];
}

int main()
{	
	int n;
	cin >> n;
	cout << numTrees(n);
	return 0;
}

