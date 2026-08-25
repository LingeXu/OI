#include <bits/stdc++.h>
#define N 1000010
typedef long long ll;
using namespace std;
int n;
int sz[N];
ll ans = 0;
vector< pair<int, int> > graph[N];
int dfs1(int u, int fa) {
    sz[u] = 1;
    for(auto& e : graph[u]) {
        if(e.second == fa)  continue;
        sz[u] += dfs1(e.second, u);
    }
    return sz[u];
}
ll dfs2(int u, int fa) {
    ll res = 0;
    for(auto& e : graph[u]) {
        int w = e.first, v = e.second;
        if(v == fa)
            continue;
        res += 1LL * w * abs(n - 2 * sz[v]);
        res += dfs2(v, u);
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(w, v));
        graph[v].push_back(make_pair(w, u));
    }
    dfs1(1, 0);
    cout << dfs2(1, 0);
    return 0;
}   