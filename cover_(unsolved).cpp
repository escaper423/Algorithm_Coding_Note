#include <iostream>
#include <vector>
using namespace std;

typedef struct
{
	int y;
	int x;
}point;

bool setblock(vector<vector<char>> &v, int ny, int nx, int type, char c)
{
	bool ret = true;
	point shape[4][3] =
	{ { { 0,0 },{ 1,0 },{ 1,1 } },
	{ { 0,0 },{ 1,0 },{ 0,1 } },
	{ { 0,0 },{ 0,1 },{ 1,1 } },
	{ { 0,0 },{ 1,0 },{ 1,-1 } } };
	//3 blocks...
	for (int block = 0; block < 3; block++)
	{
		int next_y = ny + shape[type][block].y;
		int next_x = nx + shape[type][block].x;

		//out of boundary
		if (next_y >= v.size() || next_x < 0 || next_x >= v[0].size() || next_y < 0)
		{
			return false;
		}
		else if ((v[next_y][next_x] == '#' && c == '#') || (v[next_y][next_x] == '.' && c == '.'))
		{
			return false;
		}
		v[next_y][next_x] = c;
	}
	return ret;
}
int someFunc(vector<vector<char>> &v)
{
	//finding blank

	int ny = -1, nx = -1;
	for (int k = 0; k < v.size(); k++)
	{
		for (int j = 0; j < v[k].size(); j++)
		{
			if (v[k][j] == '.')
			{
				ny = k;
				nx = j;
				break;
			}
		}
		if (ny != -1) break;
	}
	if (ny == -1) return 1;
	int ret = 0;
	//case 2 : filling blocks (attempts in 4 ways)
	for (int type = 0; type < 4; type++)
	{
		if (setblock(v, ny, nx, type, '#') == true)
		{
			ret += someFunc(v);
		}
		setblock(v, ny, nx, type, '.');
	}

	return ret;
}

int main()
{
	int test_case;
	cin >> test_case;
	for (int i = 0; i < test_case; i++)
	{
		int white_space = 0;
		int r, c;
		cin >> r >> c;
		vector<vector<char>> v(r, vector<char>(c));
		for (int row = 0; row < r; row++)
		{
			for (int col = 0; col < c; col++)
			{
				char inp;
				cin >> inp;
				if (inp == '.')
					white_space += 1;
				v[row][col] = inp;
			}
		}

		if (white_space == 0)
			cout << 1 << endl;
		else if (white_space % 3 != 0)
			cout << 0 << endl;
		else
			cout << someFunc(v) << endl;
	}
	system("pause");
	return 0;
}