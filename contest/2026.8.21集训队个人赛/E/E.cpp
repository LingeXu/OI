#include <bits/stdc++.h>
#define N 32
typedef long long ll;
using namespace std;
int n, q;
int tree[N];
int lowbit(int x) {
    return x & (-x);
}
inline void add(int pos, int delta) {
    for(int i = pos; i <= n; i += lowbit(i))    tree[i] += delta;
}
inline void query(int pos) {
    ll res = 0;
    for(int i = pos; i; i -= lowbit(i)) res += tree[i];
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    vector<int> cnt(n);
    for(int i = 0; i < n; i++) {
        cin >> cnt[i];
        add(i + 1, cnt[i]);
    }
    while(q--) {
        int op, x, y;
        cin >> op >> x >> y;
        if(op == 1)
            add(x + 1, y - (query(x + 1) - query(x)));
        else {
            int need = k - query(x + 1);
            if(need <= 0) 
                cout << 0 << '\n';
            else {
                int ans = 0;
                int dist = pos - (x + 1);
                while(need >= (1 << dist)) {
                    need -= (1 << dist);
                    ans += (1 << dist) - 1;
                    dist = 
                }
                
            }
        }
    }
    return 0;
}