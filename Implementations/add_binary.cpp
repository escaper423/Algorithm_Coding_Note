#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

//problem URL : https://leetcode.com/problems/add-binary/

using namespace std;

string addBinary(string a, string b) {

	//exception handling.
	if (!a.compare("0") && !b.compare("0"))
		return "0";

	if (!a.compare("0"))
		return b;
	if (!b.compare("0"))
		return a;


	int al = a.length();
	int bl = b.length();

	unsigned mxLength = max(al, bl);
	string res;

	//the size of result can be larger than the max length of two operand.
	//i'll explain it below
	res.resize(mxLength + 1);

	int resSize = mxLength;
	int carry = 0;
	al -= 1; bl -= 1;

	while (al >= 0 && bl >= 0) {
		int num1 = a[al] - '0';
		int num2 = b[bl] - '0';

		int rnum = num1 + num2 + carry;

		carry = rnum / 2;
		rnum = rnum % 2;
		res[resSize--] = rnum + '0';
		al--; bl--;
	}

	//string a is longer than b
	while (al >= 0) {

		int num1 = a[al--] - '0';
		int rnum = num1 + carry;

		carry = rnum / 2;
		rnum = rnum % 2;
		res[resSize--] = rnum + '0';
	}

	//and vice versa
	while (bl >= 0) {

		int num2 = b[bl--] - '0';
		int rnum = num2 + carry;

		carry = rnum / 2;
		rnum = rnum % 2;
		res[resSize--] = rnum + '0';
	}

	//processing the remaining carry e.g. "111" + "111" = "1110". 
	//in this case, the length of result is 1 character longer than max-length of operands.
	if (carry)
		res[0] = carry + '0';
	else
		res.erase(res.begin());

	return res;
}

int main() {
	string a, b;
	cin >> a >> b;
	cout << addBinary(a, b);
	return 0;
}