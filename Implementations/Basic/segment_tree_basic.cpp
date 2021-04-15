#include <iostream>
#include <vector>
#include <stack>

using namespace std;

template <class T>
long long initTree(vector<T> v, vector<long long> &seg_tree, int start, int end, int cur)
{
	if (start == end)
		seg_tree[cur] = v[start];
	else {
		int mid = (end + start) / 2;
		seg_tree[cur] = initTree(v, seg_tree, start, mid, (2 * cur) + 1) + initTree(v, seg_tree, mid + 1, end, (2 * cur) + 2);
	}
	return seg_tree[cur];
}

template <class T>
long long getSum(const vector<T> &seg_tree, int start, int end, int left, int right, int cur)
{
	if (left > end || right < start)
		return 0;
	else if (left <= start && right >= end)
		return seg_tree[cur];
	else
	{
		int mid = (start + end) / 2;
		return getSum(seg_tree, start, mid, left, right, cur * 2 + 1) + getSum(seg_tree, mid+1, end, left, right, cur * 2 + 2);
	}
}


template <class T>
void updateTree(vector<T> &seg_tree, int idx, int cur, T diff, int start, int end)
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
template <class T>
void updateQuery(vector<T> v, vector<T> &seg_tree, int idx, T new_val, int start, int end)
{
	T diff = new_val - v[idx];
	updateTree(seg_tree, idx, 0, diff, start, end);
}

int main()
{
	int n,m,k;
	cin >> n >> m >> k;
	vector<long long> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	int h = static_cast<int>(ceil(log2(n)));
	int tree_size = (1 << (h+1)) - 1;
	vector<long long> seg_tree(tree_size); 
	initTree(v, seg_tree, 0, n-1, 0);
	
	
	updateQuery(v,seg_tree, 0, (long long)10, 0, n-1);
	
	system("pause");
	return 0;
}
