#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int l, k, c, idx = 1e9;
int cut_length = (int)1e9, cut_pos = (int)1e9;
vector<int> pos;

bool doCut(int length) {
	int pre_cut = 0;
	int can = c;

	for (int i = pos.size() - 1; i > 0; --i) {
		int cur_length = pos[i] - pos[i-1];
		//cout << "cur_length: " << cur_length;
		if (cur_length > length)
			return false;

		//cout << " accu length: " << pre_cut + cur_length << endl;
		if (pre_cut + cur_length > length) {
			pre_cut = (pos[i] - pos[i-1]);
			//cout << "cutted - pos: " << cuts[i].first << endl;
			can--;
		}
		else
			pre_cut += (pos[i] - pos[i-1]);

		if (can == 0) {
			if (pos[i] > length)
				return false;
			else {
				idx = i;
				return true;
			}
		}
		
	}
	idx = 1;
	return true;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	cin >> l >> k >> c;

	pos.push_back(0);

	for (int i = 0; i < k; i++) {
		int tmp;
		cin >> tmp;
		pos.push_back(tmp);
	}
	pos.push_back(l);
	std::sort(pos.begin(), pos.end());

	int mid;
	int left = 0, right = l;

	while (left <= right) {
		//cout << "left: " << left << " right: " << right;
		mid = left + (right - left) / 2;
		//cout << " length: " << mid << endl;
		if (doCut(mid)) {
			cut_length = min(cut_length, mid);
			right = mid - 1;
		}
		else
			left = mid + 1;
	}

	cut_pos = (idx == 1) ? pos[1] : pos[idx];
	cout << cut_length << " " << cut_pos;
	return 0;
}

/* inputs 
102 5 4
31 5 1 48 61

9 2 1
4 5

100 10 8
8 18 38 28 48 58 88 78 68 98

100 10 8
8 18 28 38 48 58 68 78 88 98
*/