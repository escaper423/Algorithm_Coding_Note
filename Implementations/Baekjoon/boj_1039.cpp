#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n; int k;
	cin >> n >> k;
	string tmp = to_string(n);
	int len = tmp.length();

	queue<string> q;
	q.push(tmp);
	int mx = -1;
	string mx_str;
	int times = 1;
	unordered_set<string> us;
	while (!q.empty() && times <= k) {

		int ql = q.size();
		
		for (int qs = 0; qs < ql; qs++) {
			auto cur = q.front(); q.pop();
			for (int i = 0; i < len - 1; i++) {
				for (int j = i + 1; j < len; j++) {
					string temp = cur;
					swap(temp[i], temp[j]);
					//cout << "S: " << temp << " " << cur.second << endl;
					if (us.find(temp) == us.end() && temp[0] != '0') {
						us.insert(temp);
						q.push(temp);
						int intval = stoi(temp);
						if (times == k && mx < intval)
						{
							mx = intval;
							mx_str = temp;
						}
					}
				}
			}
		}
		times++;
		us.clear();
	}

	if (mx_str[0] == '0' || mx == -1)
		cout << -1;
	else
		cout << mx_str;

	return 0;
}
