#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;


stack<int> numStack;

int printDecoded(string str, int &pos) {
	int res = 0;

	for (; pos < str.length(); pos++) {
		//0~9
		if (isdigit(str[pos])) {
			if (pos != str.length() - 1 && str[pos+1] == '(') {
				numStack.push(str[pos] - '0');
			}
			else
				res++;
		}
		//'('
		else if (str[pos] == '(') {
			int to_add = printDecoded(str, ++pos);
			res += to_add;
		}
		//')'
		else{
			int rep = numStack.top(); 
			numStack.pop();

			return res * rep;
		}
	}
	return res;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string str;
	cin >> str;
	
	int pos = 0;
	cout << printDecoded(str, pos);
	return 0;
}