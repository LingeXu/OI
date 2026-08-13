#include <bits/stdc++.h>
#define N 500050
typedef long long ll;
using namespace std;
int n, m;
int a[N], diff[N];
ll tree[N];
int lowbit(int x) {
    return x & (-x);
}
void add(int pos, int delta) {
    for(int i = pos; i <= n; i += lowbit(i))    tree[i] += 1LL * delta;
}
ll query(int pos) {
    ll res = 0;
    for(int i = pos; i >= 1; i -= lowbit(i))    res += tree[i];
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        diff[i] = a[i] - a[i - 1];
        add(i, diff[i]);
    }
    for(int i = 1; i <= m; i++) {
        int op;
        cin >> op;
        if(op == 1) {
            int x, y, k;
            cin >> x >> y >> k;
            add(x, k);
            add(y + 1, -k);
        }
        else {
            int x;
            cin >> x;
            cout << query(x) << '\n';
        }
    }
    return 0;
}