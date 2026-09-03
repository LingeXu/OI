#include <bits/stdc++.h>
#define N 100010
#define LOG 20
using namespace std;
int n, q, m;
int f[N], depth[N], parent[N][LOG], mx[N];  
vector<int> graph[N];
void dfs(int u, int fa) {
    depth[u] = depth[fa] + 1;
    parent[u][0] = fa;
    mx[u] = max(mx[fa], u);
    for(int v : graph[u]) {
        if(v == fa)
            continue;
        dfs(v, u);
    }
}
void init() {
    for(int i = 1; i < LOG; i++)
        for(int j = 1; j < n; j++)
            parent[j][i] = parent[parent[j][i - 1]][i - 1];
}
int lca(int u, int v) {
    if(depth[u] < depth[v])
        swap(u, v);
    for(int i = LOG - 1; i >= 0; i--)
        if(depth[parent[u][i]] >= depth[v])
            u = parent[u][i];
    if(u == v)  return u;
    for(int i = LOG - 1; i >= 0; i--) {
        if(parent[u][i] != parent[v][i]) {
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i = 1; i < n; i++) {
        cin >> f[i];
        graph[f[i]].push_back(i);
        graph[i].push_back(f[i]);
    }
    dfs(0, 0);
    init();
    cin >> q;
    while(q--) {
        cin >> m;
        vector<int> node(m);
        for(int i = 0; i < m; i++)
            cin >> node[i];
        int ans = node[0];
        for(int i = 1; i < m; i++)
            ans = lca(ans, node[i]);
        cout << mx[ans] << '\n';  
    }
    return 0;
}