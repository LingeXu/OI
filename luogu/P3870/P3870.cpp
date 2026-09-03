#include <bits/stdc++.h>
#define N 100010
using namespace std;
int n, m, c, a, b;
int tree[4 * N], lazy[4 * N];
void build(int node, int l, int r) {
    if(l == r) {
        tree[node] = 0;
        return;
    }
    int mid = (l + r) >> 1;
    build(2 * node, l, mid);
    build(2 * node + 1, mid + 1, r);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}
void make_tag(int node, int l, int r) {
    tree[node] = r - l + 1 - tree[node];
    lazy[node] ^= 1;
}
void push_down(int node, int l, int r) {
    if(lazy[node] == 0)
        return;
    int mid = (l + r) >> 1;
    make_tag(2 * node, l, mid);
    make_tag(2 * node + 1, mid + 1, r);
    lazy[node] = 0;
}
void update(int node, int l, int r, int L, int R) {
    if(L <= l && r <= R) {
        make_tag(node, l, r);
        return;
    }
    push_down(node, l, r);
    int mid = (l + r) >> 1;
    if(L <= mid)    update(2 * node, l, mid, L, R);
    if(R > mid)    update(2 * node + 1, mid + 1, r, L, R);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}
int query(int node, int l, int r, int L, int R) {
    if(L <= l && r <= R)
        return tree[node];
    push_down(node, l, r);
    int mid = (l + r) >> 1, res = 0;
    if(L <= mid)    res += query(2 * node, l, mid, L, R);
    if(R > mid)    res += query(2 * node + 1, mid + 1, r, L, R);
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    build(1, 1, n);
    while(m--) {
        cin >> c >> a >> b;
        if(c == 0) 
            update(1, 1, n, a, b);
        else
            cout << query(1, 1, n, a, b) << '\n';
    }
    return 0;
}