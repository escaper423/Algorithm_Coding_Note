#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void solution_stack(vector<int> v, int tc)
{
	int mx = 0;
	int width, height;
	vector<int> A(tc, 1);
	stack<int> s;

	for (int i = 0; i < tc; i++)
	{
		while (!s.empty() && v[s.top()] > v[i])
		{
			height = a[s.top()];
			s.pop();
			if (s.empty())
				width = i;
			else
				width = i - v[s.top()] - 1;

			if (mx < width * height)
				mx = width * height;
		}
		s.push(i);
	}

	while (!s.empty() && v[i] < v[s.top()])
	{
		height = v[s.top()];
		s.pop();
		if (s.empty())
			width = tc;
		else width = v[s.top()] - i - 1;

		if (mx < width * height)
			mx = width * height;
	}

	cout << mx << endl;
}

int main()
{
	int tc;
	while (1) {
		cin >> tc;
		if (tc == 0) break;

		vector<int> v(tc);
		for (int i = 0; i < tc; i++)
			cin >> v[i];

		solution_stack(v, tc);
		v.clear();
	}
	//system("pause");
	return 0;
}
