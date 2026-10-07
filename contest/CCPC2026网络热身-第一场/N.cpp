#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 1505;
int n;
int c[MAXN], k[MAXN];
vector<pair<int, int> > g[MAXN];
int ans;
int root; 
void dfs(int u, int fa, int d, int x) {
    if (u > root && d <= k[root] && d <= k[u] && x == 0)
        ans++;
    for (auto &e : g[u]) {
        int w = e.first, v = e.second; 
        if (v == fa)
            continue;
        dfs(v, u, d + w, x ^ c[v]);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    for (int i = 1; i <= n; i++)
        cin >> k[i];
    for (int i = 1; i <= n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back(make_pair(w, v));
        g[v].push_back(make_pair(w, u));
    }
    for (root = 1; root <= n; root++)
        dfs(root, 0, 0, c[root]);
    cout << ans << '\n';
    return 0;
}
