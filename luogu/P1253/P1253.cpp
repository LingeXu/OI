#include <bits/stdc++.h>
#define int long long
#define N 1000010
using namespace std;
int n, m;
int a[N], tree[4 * N], lazy_add[4 * N], lazy_set[4 * N];
void build(int node, int l, int r) {
    if(l == r) {
        tree[node] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(2 * node, l, mid);
    build(2 * node + 1, mid + 1, r);
    tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}
void make_tag(int node, int l, int r, int x, int type) {
    if(type == 1) {
        lazy_set[node] = x;
        lazy_add[node] = 0;
        tree[node] = x;
        return;
    }
    else {
        if(lazy_set[node] == 1e16)
            lazy_add[node] += x;
        else    lazy_set[node] += x;
        tree[node] += x;
    }
}
void push_down(int node, int l, int r) {
    int mid = (l + r) >> 1;
    if(lazy_set[node] != 1e16) {
        make_tag(2 * node, l, mid, lazy_set[node], 1);
        make_tag(2 * node + 1, mid + 1, r, lazy_set[node], 1);
        lazy_set[node] = 1e16;
        return;
    }
    if(lazy_add[node] != 0) {
        make_tag(2 * node, l, mid, lazy_add[node], 2);
        make_tag(2 * node + 1, mid + 1, r, lazy_add[node], 2);
        lazy_add[node] = 0;
    }
}
void update(int node, int l, int r, int L, int R, int x, int type) {
    if(L <= l && r <= R) {
        make_tag(node, l, r, x, type);
        return;
    }
    push_down(node, l, r);
    int mid = (l + r) >> 1;
    if(L <= mid)    update(2 * node, l, mid, L, R, x, type);
    if(R > mid)    update(2 * node + 1, mid + 1, r, L, R, x, type);
    tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}
int query(int node, int l, int r, int L, int R) {
    if(L <= l && r <= R)   
        return tree[node];
    push_down(node, l, r);
    int mid = (l + r) >> 1;
    int res = -1e16;
    if(L <= mid)    res = max(res, query(2 * node, l, mid, L, R));
    if(R > mid)    res = max(res, query(2 * node + 1, mid + 1, r, L, R));
    return res;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= 4 * n; i++)
        lazy_set[i] = 1e16;
    build(1, 1, n);
    while(m--) {
        int op, l, r;
        cin >> op >> l >> r;
        if(op == 1 || op == 2) {
            int x;
            cin >> x;
            update(1, 1, n, l, r, x, op);
        }
        else    cout << query(1, 1, n, l, r) << '\n';
    }
    return 0;
}