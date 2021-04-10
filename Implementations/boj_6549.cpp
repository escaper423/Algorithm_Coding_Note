#include <iostream>
#include <cstring>
#define ll long long
using namespace std;

int arr[100000] = { 0 };
int seg[400000] = { 0 };

void buildTree(int cur, int s, int e) {
	if (s == e) {
		seg[cur] = s;
		return;
	}

	int mid = s + (e - s) / 2;
	buildTree(cur * 2 + 1, s, mid);
	buildTree(cur * 2 + 2, mid + 1, e);
	seg[cur] = (arr[seg[cur * 2 + 1]] < arr[seg[cur * 2 + 2]]) ? seg[cur * 2 + 1] : seg[cur * 2 + 2];
}

int getMinIndex(int cur, int s, int e, int qs, int qe) {
	if (qs > e || qe < s)
		return -1;

	if (qs <= s && qe >= e)
		return seg[cur];

	int mid = s + (e - s) / 2;
	
	int mi1 = getMinIndex(cur * 2 + 1, s, mid, qs, qe);
	int mi2 = getMinIndex(cur * 2 + 2, mid + 1, e,qs, qe);
	if (mi1 == -1)
		return mi2;
	else if (mi2 == -1)
		return mi1;
	else
		return arr[mi1] < arr[mi2]?mi1:mi2;
}

ll largestArea(int s, int e, int n) {
	int pivot = getMinIndex(0, 0, n-1, s, e);
	ll area = arr[pivot] * static_cast<ll>(e - s + 1);
	if (s < pivot) {
		area = max(area,largestArea(s, pivot - 1,n));
	}
	if (pivot < e){
		area = max(area,largestArea(pivot + 1, e, n));
	}
	return area;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	while (1) {
		int n;
		cin >> n;
		if (n == 0)
			break;

		for (int i = 0; i < n; i++)
			cin >> arr[i];
		
		buildTree(0, 0, n - 1);
		cout << largestArea(0, n - 1, n) << endl;
		memset(arr, 0, sizeof(arr));
		memset(seg, 0, sizeof(arr));
	}
	return 0;
}