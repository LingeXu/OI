#include <bits/stdc++.h>
#define N 500050
typedef long long ll;
using namespace std;
int n, m;
ll tree[N];
int lowbit(int x) {
    return x & (-x);
}
void add(int delta, int pos) {
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
        int a;
        cin >> a;
        add(a, i);
    }
    for(int i = 1; i <= m; i++) {
        int op, x, y;
        cin >> op >> x >> y;
        if(op == 1)
            add(y, x);
        else    cout << query(y) - query(x - 1) << '\n';
    }
    return 0;
}