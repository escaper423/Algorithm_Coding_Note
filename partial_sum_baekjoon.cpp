#include <iostream>
#include <vector>

using namespace std;

long long initTree(long long v[], long long *seg_tree, int start, int end, int cur)
{
	if (start == end)
		seg_tree[cur] = v[start];
	else {
		int mid = (end + start) / 2;
		seg_tree[cur] = initTree(v, seg_tree, start, mid, (2 * cur) + 1) + initTree(v, seg_tree, mid + 1, end, (2 * cur) + 2);
	}
	return seg_tree[cur];
}

long long getSum(long long *seg_tree, int start, int end, int left, int right, int cur)
{
	if (left > end || right < start)
		return 0;
	else if (left <= start && right >= end)
		return seg_tree[cur];
	int mid = (start + end) / 2;
	return getSum(seg_tree, start, mid, left, right, (2*cur) + 1) + getSum(seg_tree, mid+1, end, left, right, (2*cur) + 2);
}


void updateTree(long long *seg_tree, int idx, int cur, long long diff, int start, int end)
{
	if (idx < start || idx > end)
		return;
	seg_tree[cur] += diff;
	if (start != end)
	{
		int mid = (start + end) / 2;
		updateTree(seg_tree, idx,2*cur+1,diff, start, mid);
		updateTree(seg_tree, idx,2*cur+2,diff, mid+1, end);
	}
}

void updateQuery(long long v[], long long *seg_tree, int idx, long long new_val, int start, int end)
{
	long long diff = new_val - v[idx];
	v[idx] = new_val;
	updateTree(seg_tree, idx, 0, diff, start, end);
}

int main()
{
	int n,m,k;
	cin >> n >> m >> k;
	long long A[1000001];
	for (int i = 0; i < n; i++)
		cin >> A[i];

	int h = static_cast<int>(ceil(log2(n)));
	int tree_size = (1 << (h+1)) - 1;
	long long *seg_tree = new long long[tree_size];
	initTree(A, seg_tree, 0, n-1, 0);

	for (int i = 0; i < k + m; i++)
	{
		int a;
		long long b, c;
		cin >> a >> b >> c;
		if (a == 1)
		{
			updateQuery(A, seg_tree, (int)b - 1, c, 0, n - 1);
		}
		else if (a == 2)
		{
			cout << getSum(seg_tree, 0, n-1, (int)b-1, (int)c-1, 0) << endl;
		}
		else return -1;
	}
	return 0;
}