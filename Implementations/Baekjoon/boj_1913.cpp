#include <iostream>

using namespace std;

int dir_y[4] = {-1,0,1,0};
int dir_x[4] = { 0,1,0,-1 };

int arr[1000][1000] = { 0 };

int n, num;
int cur = 1;
int mult = 1;

bool isValid(int x) {
	return x > 0 && x <= n;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	pair<int, int> pt;

	cin >> n >> num;

	int cy = (n>>1)+1, cx = (n>>1)+1;
	int dir = 0; int rot = 0;

	while (isValid(cy) && isValid(cx)) {
		for (int i = 0; i < mult; i++)
		{
			if (cur == num) 
				pt = { cy,cx };	

			arr[cy][cx] = cur++;
			cy += dir_y[dir];
			cx += dir_x[dir];
		} rot++;

		if (rot == 2) {
			rot = 0;
			mult += 1;
		}
		dir = (dir + 1) % 4;
	}
	for (int k = 1; k <= n; k++)
	{
		for (int l = 1; l <= n; l++) {
			cout << arr[k][l] << " ";
		}
		cout << endl;
	}
	cout << pt.first << " " << pt.second;
	return 0;
}