#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s = "abc";
	int rot = -3;
	for (auto &it : s)
	{
		if (rot > 0) cout << static_cast<char>(((it - 'a' + rot) % 26) + 'a');
		else cout << static_cast<char>((it - ('a' - rot) % 26) % 26 + 'a');
	}
	system("pause");
	return 0;

}
