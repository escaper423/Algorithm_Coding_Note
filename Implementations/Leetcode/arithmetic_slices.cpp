#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
//problem URL : https://leetcode.com/problems/arithmetic-slices/
/* Brute Force
int numberOfArithmeticSlices(vector<int>& A) {
	int N = A.size();
	int ans = 0;

	if (N < 3)
		return 0;

	for (int p = 3; p <= N; p++)
	{
		for (int i = 0; i <= N - p; i++)
		{
			bool is_seq = true;
			int diff = A[i + 1] - A[i];
			for (int k = 1; k < p; k++)
			{
				if (A[i + k] - A[i + k - 1] == diff)
					continue;
				else {
					is_seq = false;
					break;
				}
			}
			if (is_seq)
				ans++;

		}
	}
	return ans;
}
*/

//DP
int numberOfArithmeticSlices(vector<int>& A) {
	int N = A.size();
	vector<int> D(N, 0);
	int ans = 0;

	if (N < 3)
		return 0;

	for (int i = 2; i < N; i++)
	{
		if (A[i] - A[i - 1] == A[i - 1] - A[i - 2])
		{
			D[i] = D[i - 1] + 1;
			ans += D[i];
		}
	}

	return ans;
}


int main()
{
	vector<int> nums;
	string str;
	getline(cin,str);
	stringstream ss(str);
	string t;
	while (getline(ss, t, ' '))
		nums.push_back(stoi(t));
		
	cout << numberOfArithmeticSlices(nums);

	system("pause");
	return 0;
}

