#include <iostream>
using namespace std;

int main()
{
	int tc;
	cin >> tc;
	for (int t = 0; t < tc; t++)
	{
		unsigned int input_num;
		unsigned int input_mask = 0xFFu;
		cin >> input_num;
		cout << ((input_num >> 24) | ((input_num << 8) & 0x00FF0000) | ((input_num >> 8) & 0x0000FF00) | (input_num << 24)) << endl;

	}
	return 0;
}
