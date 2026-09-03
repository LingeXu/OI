#include <bits/stdc++.h>
#define int long long
#define N 100001
using namespace std;
int n, m;
int a[N], diff[N], tree[4 * N], lazy[4 * N];
void build(int node, int l, int r) {
    if(l == r) {
        tree[node] = diff[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(2 * node, l, mid);
    build(2 * node + 1, mid + 1, r);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
} 
void make_tag(int node, int l, int r, int delta) {
    lazy[node] += delta;
    tree[node] += delta * (r - l + 1);
}
void push_down(int node, int l, int r) {
    if(lazy[node] == 0)
        return;
    int mid = (l + r) >> 1;
    make_tag(2 * node, l, mid, lazy[node]);
    make_tag(2 * node + 1, mid + 1, r, lazy[node]);
    lazy[node] = 0;
}
void update(int node, int l, int r, int L, int R, int delta) {
    if(L <= l && r <= R) {
        make_tag(node, l, r, delta);
        return;
    }
    push_down(node, l, r);
    int mid = (l + r) >> 1;
    if(L <= mid)    update(2 * node, l, mid, L, R, delta);
    if(R > mid)    update(2 * node + 1, mid + 1, r, L, R, delta);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}
int query(int node, int l, int r, int L, int R) {
    if(L <= l && r <= R) 
        return tree[node];
    push_down(node, l, r);
    int mid = (l + r) >> 1;
    int res = 0;
    if(L <= mid)    res += query(2 * node, l, mid, L, R);
    if(R > mid)    res += query(2 * node + 1, mid + 1, r, L, R);
    return res;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        diff[i] = a[i] - a[i - 1];
    }
    build(1, 1, n);
    while(m--) {
        int op;
        cin >> op;
        if(op == 1) {
            int l, r, K, D;
            cin >> l >> r >> K >> D;
            int ft = K, lt = K + D * (r - l);
            update(1, 1, n, l, l, ft);
            if(r + 1 <= n)
                update(1, 1, n, r + 1, r + 1, -lt);
            if(l + 1 <= r)
                update(1, 1, n, l + 1, r, D);
        }
        else {
            int p;
            cin >> p;
            cout << query(1, 1, n, 1, p) << '\n';
        }
    }
    return 0;
}