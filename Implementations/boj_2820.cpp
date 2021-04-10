#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#pragma warning(disable: 4996)

using namespace std;

int st[2000001];
int lazy[2000001];
int arr[500001];
int l[500001] = { 0 };
int r[500001] = { 0 };
vector<vector<int>> adj;
int n,m, cnt = 0;

void update_lazy(int cur, int l, int r) {
    if (lazy[cur] != 0) {
        st[cur] += (r - l + 1) * lazy[cur];

        if (l != r) {
            lazy[cur * 2] += lazy[cur];
            lazy[cur * 2 + 1] += lazy[cur];
        }
    }
    lazy[cur] = 0;
}

void update(int qs, int qe, int ss, int se, int cur, int diff) {
    update_lazy(cur,ss,se);

    if (qs > se || qe < ss)
        return;

    if (qs <= ss && qe >= se) {
        lazy[cur] += diff;
        update_lazy(cur,ss,se);
        return;
    }

    int mid = ss + (se - ss) / 2;
    update(qs, qe, ss, mid, cur * 2,diff);
    update(qs, qe, mid+1, se, cur * 2 + 1,diff);
    st[cur] = st[cur * 2] + st[cur * 2 + 1];
}

int query(int qs, int qe, int ss, int se, int cur) {
    update_lazy(cur,ss,se);
    if (qs > se || qe < ss)
        return 0;
    if (qs <= ss && qe >= se) {
        return st[cur];
    }
    int mid = ss + (se - ss) / 2;
    return query(qs, qe, ss, mid, cur * 2) + query(qs, qe, mid + 1, se, cur * 2 + 1);
}

void dfs(int idx) {
    l[idx] = ++cnt;
    for (auto& v : adj[idx]) {
        if(!l[v])
            dfs(v);
    }
    r[idx] = cnt;
}

int main() {

    scanf("%d %d",&n,&m);
    adj.resize(n + 1);
    scanf("%d", &arr[1]);
    for (int i = 2; i <= n; i++) {
        int v, s;
        scanf("%d %d", &v, &s);
        arr[i] = v;
        adj[s].push_back(i);
    }
    dfs(1);

    for (int i = 1; i <= n; i++) {
        update(l[i], l[i], 1, n, 1, arr[i]);
    }

    for (int i = 0; i < m; i++) {
        char cmd;
        int v, val;
        scanf("%*c%c",&cmd);

        if (cmd == 'p') {
            scanf("%d %d", &v, &val);
            update(l[v]+1, r[v], 1, n, 1, val);
        }
        else {
            scanf("%d", &v);
            printf("%d\n",query(l[v], l[v], 1, n, 1));
        }
    }
    return 0;
}

