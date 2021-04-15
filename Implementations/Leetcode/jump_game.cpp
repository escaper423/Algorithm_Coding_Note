#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int v[100][100];
int D[100][100];
int Jump(int y, int x ,int n)
{
	if (y == n - 1 && x == n - 1)
		return 1;
	else if (y >= n || x >= n)
		return 0;
	if (D[y][x] != -1)
		return D[y][x];
	int jmp = v[y][x];
	return D[y][x] = (Jump(y + jmp, x,n) || Jump(y, x + jmp,n));
}

int ddd()
{
	int i = 1;
	return i = 1 + 1;
}
int main() {
	int t;
	cin >> t;
	for (int test_case = 0; test_case < t; test_case++)
	{
		int n;
		cin >> n;
		memset(D, -1, sizeof(D));
		for (int i = 0; i < n; i++)
		{
			for (int k = 0; k < n; k++)
			{
				cin >> v[i][k];
			}
		}
		int start_y = 0, start_x = 0;
		if (Jump(start_y, start_x,n))
			cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	//system("pause");
	return 0;
}