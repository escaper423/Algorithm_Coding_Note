#include <iostream>
#include <string>
#include <stack>
using namespace std;

int getPriority(const char c)
{
	switch (c)
	{
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	default:
		return -1;
	}

}

template <class T>
void someOperation(stack<T> &stac, const char cur_op)
{
	char prev_op;
	if (!stac.empty())
		prev_op = stac.top();

	if (stac.empty() || (getPriority(prev_op) <= getPriority(cur_op)));
	else
	{
		while (!stac.empty() && (getPriority(cur_op) <= getPriority(stac.top())) )
		{
			cout << stac.top();
			stac.pop();
		}
	}
	stac.push(cur_op);
}

int main()
{
	stack<char> stac;
	string s;
	getline(cin, s);

	for (auto &it : s)
	{
		switch (it)
		{
		case '+':
		case '-':
		case '*':
		case '/':
			someOperation(stac, it);
			break;
		case '(':
			stac.push(it);
			break;
		case ')':
			while (stac.top() != '(')
			{
				if (stac.empty())
				{
					cout << "Error" << endl;
					break;
				}
				cout << stac.top();
				stac.pop();
			}
			stac.pop();
			break;
		default:
			cout << it;
			break;
		}
	}

	while (!stac.empty() && stac.top() != '(')
	{
		cout << stac.top();
		stac.pop();
	}
	return 0;
}
