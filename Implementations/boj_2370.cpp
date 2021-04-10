#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> st;
vector<int> lazy;
int n;

void update(int qs, int qe, int ss, int se, int cur) {
    if (lazy[cur] != 0) {
        st[cur] = (qe - qs + 1);
        if (ss != se) {
            lazy[cur * 2 + 1] = 1;
            lazy[cur * 2 + 2] = 1;
        }
        lazy[cur] = 0;
    }
    //out of bound
    if (se < qs || ss > qe || ss > se)
        return;
    
    if (ss == se)
    {
        st[cur] = 1;
        return;
    }

    int mid = ss + (se - ss) / 2;
    update(qs, qe, ss, mid, cur * 2 + 1);
    update(qs, qe, mid+1, se, cur * 2 + 2);
    st[cur] = st[cur * 2 + 1] + st[cur * 2 + 2];
}

int query(int qs, int qe, int ss, int se, int cur) {

    if (qs < 0 || qe > 2 * n - 2 || qs > qe)
        return 0;

    if (lazy[cur] != 0) {
        st[cur] = (qe - qs + 1);
        if (ss != se) {
            lazy[cur * 2 + 1] = 1;
            lazy[cur * 2 + 2] = 1;
        }
        lazy[cur] = 0;
    }

    if (se < qs || ss > qe)
        return 0;

    if (ss >= qs && se <= qe)
        return st[cur];

    int mid = ss + (se - ss) / 2;
    return query(qs, qe, ss, mid, cur * 2 + 1) + query(qs, qe, mid + 1, se, cur * 2 + 2);
}

int main() {
    int res = 0;
    cin >> n;
    
    vector<int> arr;
    vector<pair<int, int>> p;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        arr.emplace_back(x);
        arr.emplace_back(y);
        p.push_back({ x,y });
    }
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());

    st.resize(n * 8 - 1, 0);
    lazy.resize(n * 8 - 1, 0);

    for (int i = n - 1; i >= 0; i--) {
        int l = lower_bound(arr.begin(), arr.end(), p[i].first) - arr.begin();
        int r = lower_bound(arr.begin(), arr.end(), p[i].second) - arr.begin();
        if (query(l, r, 0, arr.size() - 1, 0) != (r - l + 1))
            res++;

        update(l, r, 0, arr.size() - 1, 0);
    }
    cout << res;
    return 0;
}

