#include <bits/stdc++.h>
#define int long long
#define N 100010
using namespace std;
int n, m;
int sum[4 * N], lazy[4 * N];
vector<int> a(N);
void build(int node, int l, int r) {
    if(l == r) {
        sum[node] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * node, l, mid);
    build(2 * node + 1, mid + 1, r);
    sum[node] = sum[2 * node] + sum[2 * node + 1];
}
void push_down(int node, int l, int r) {
    if(lazy[node] == 0)    return;
    int mid = (l + r) / 2;
    lazy[2 * node] += lazy[node];
    lazy[2 * node + 1] += lazy[node];
    sum[2 * node] += lazy[node] * (mid - l + 1);
    sum[2 * node + 1] += lazy[node] * (r - mid);
    lazy[node] = 0;
}
void update(int node, int l, int r, int ql, int qr, int delta) {
    if(ql <= l && r <= qr) {
        sum[node] += delta * (r - l + 1);
        lazy[node] += delta;
        return;
    }
    push_down(node, l, r);
    int mid = (l + r) / 2;
    if(ql <= mid)    update(2 * node, l, mid, ql, qr, delta);
    if(mid < qr)    update(2 * node + 1, mid + 1, r, ql, qr, delta);
    sum[node] = sum[2 * node] + sum[2 * node + 1];
}
int query(int node, int l, int r, int ql, int qr) {
    if(ql <= l && r <= qr)    return sum[node];
    push_down(node, l, r);
    int mid = (l + r) / 2;
    int res = 0;
    if(ql <= mid)    res += query(2 * node, l, mid, ql, qr);
    if(mid < qr)    res += query(2 * node + 1, mid + 1, r, ql, qr);
    return res;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        a[i] = val;
    }
    build(1, 1, n);
    while(m--) {
        int op;
        cin >> op;
        if(op == 1) {
            int x, y, k;
            cin >> x >> y >> k;
            update(1, 1, n, x, y, k);
        }
        else {
            int x, y;
            cin >> x >> y;
            cout << query(1, 1, n, x, y) << '\n';
        }
    }
    return 0;
}