#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 1505
int n, cnt = 0;
int c[N], k[N];
vector< pair<int, int> > graph[N];
void dfs(int root, int u, int fa, int d, int x) {
    if(d <= k[root] && d <= k[u] && x == 0 && root < u)   cnt++;
    for(auto e : graph[u]) {
        if(e.second == fa) 
            continue;
        dfs(root, e.second, u, d + e.first, x ^ c[e.second]);
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> c[i];
    for(int i = 1; i <= n; i++)
        cin >> k[i];
    for(int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(w, v));
        graph[v].push_back(make_pair(w, u));
    }
    for(int i = 1; i <= n; i++)
        dfs(i, i, 0, 0, c[i]);
    cout << cnt;
    return 0;
}