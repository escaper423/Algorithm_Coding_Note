#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <iomanip>
#include <queue>
#include <chrono>
#pragma warning(disable:4996)
using namespace std;

void updateBIT(int idx, int n, vector<int> &b, int val)
{
	int cur_idx = idx + 1;
	while (cur_idx <= n)
	{
		b[cur_idx] += val;
		cur_idx += cur_idx & (-cur_idx);
	}
}

int getSum(vector<int> &b, int idx)
{
	int sum = 0;
	int cur_idx = idx + 1;
	while (cur_idx > 0)
	{
		sum += b[cur_idx];
		cur_idx -= cur_idx & (-cur_idx);
	}
	return sum;
}

void initBIT(vector<int> &b, vector<int> arr, int size)
{
	for (int i = 0; i < size; i++)
		updateBIT(i, size, b, arr[i]);
}
int main()
{
	vector<int> arr = { 1,2,3,4,5 };
	vector<int> BIT(arr.size() + 1, 0);
		initBIT(BIT, arr, arr.size());
		cout << getSum(BIT, 3) << endl;
		cout << getSum(BIT, 1) << endl;
		updateBIT(4, arr.size(), BIT, 3);
	cout << getSum(BIT, 3) << endl;
	cout << getSum(BIT, 4) << endl;
	

	return 0;
}
