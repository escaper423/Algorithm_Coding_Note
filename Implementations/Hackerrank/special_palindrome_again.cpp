#include <iostream>
#include <string>
using namespace std;

long substrCount(int n, string s) {
	long ret = n;
	int diff = -1;
	for (int i = 0; i < n; i++)
	{
		diff = -1;
		for (int j = i + 1; j < n; j++)
		{
			if (s[i] == s[j])
			{
				if (diff == -1 || diff == (i + j) / 2)
				{
					ret++;
					if (diff != -1)
						break;
				}
			}
			else
			{
				if (diff == -1)
					diff = j;
				else break;
			}
		}
	}
	return ret;
}

int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	cout << substrCount(n, s);
	return 0;
}