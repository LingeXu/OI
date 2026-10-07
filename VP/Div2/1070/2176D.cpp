#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 998244353;
int t, n, m;
struct edge {
    int u, v, val;
};
bool cmp(edge a, edge b) {
    return a.val > b.val;
}
void solve() {
    cin >> n >> m;
    vector<int> a(n + 1);
    vector<edge> e(m);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 0; i < m; i++) {
        cin >> e[i].u >> e[i].v;
        e[i].val = a[e[i].v];
    }
    sort(e.begin(), e.end(), cmp);
    int ans = 0;
    map<pair<int, int>, int> dp;
    for(int i = 0; i < m; i++) {
        int delta = (1 + dp[make_pair(e[i].v, a[e[i].u] + e[i].val)]) % MOD;
        dp[make_pair(e[i].u, e[i].val)] = (dp[make_pair(e[i].u, e[i].val)] + delta) % MOD;
        ans = (ans + delta) % MOD;
    }
    cout << ans << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--)  solve();
    return 0;
}