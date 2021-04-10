#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<queue>

#define pii pair<int,int>
#define inf 0x3f3f3f3f	

using namespace std;

typedef struct line{
	int len;
	int left;
	int right;
	line(int v, int l, int r) : len(v), left(l), right(r)
	{}
}line;

int main() {
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	int n, k;
	int res = 0;
	cin >> n >> k;

	vector<line> arr(n+1,line(inf,0,0));
	int tmp = 0;
	for (int i = 1; i <= n; i++) {
		int inp; cin >> inp;
		arr[i] = line(inp - tmp,i-1,i+1);
		tmp = inp;
		if (i > 1)
			pq.push({ arr[i].len, i });
	}

	arr[2].left = 0;
	arr[n].right = 0;

	while (k--) {
		while (pq.top().first != arr[pq.top().second].len) pq.pop();
		auto cur = pq.top(); pq.pop();
		res += cur.first;
		int idx = cur.second;
		int l = arr[idx].left;
		int r = arr[idx].right;

		arr[idx].len = (l && r) ? arr[l].len + arr[r].len - arr[idx].len : inf;
		arr[l].len = arr[r].len = inf;

		int nl = arr[l].left;
		int nr = arr[r].right;

		arr[idx].left = nl;
		arr[idx].right = nr;

		arr[nl].right = idx;
		arr[nr].left = idx;

		pq.push({arr[idx].len, idx});
	}
	cout << res;
	return 0;
}