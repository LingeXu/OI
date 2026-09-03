#include <bits/stdc++.h>
#define N 200020
#define LOG 20
using namespace std;
int n, k, q;
int depth[N], dis[N], parent[N][LOG];
vector<int> graph[N];
void dfs(int u, int fa, int cur) {
    depth[u] = cur;
    parent[u][0] = fa;
    for(int v : graph[u]) {
        if(v == fa)
            continue;
        dfs(v, u, cur + 1);
    }
}
void init() {
    for(int i = 1; i < LOG; i++)
        for(int j = 1; j <= n; j++)
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
    cin >> n >> k >> q;
    for(int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    memset(dis, 0x3f3f3f3f, sizeof(dis));
    queue<int> qu;
    for(int i = 0; i < k; i++) {
        int p;
        cin >> p;
        dis[p] = 0;
        qu.push(p);
    }
    while(!qu.empty()) {
        int x = qu.front();
        qu.pop();
        for(int v : graph[x])
            if(dis[v] > dis[x] + 1) {
                dis[v] = dis[x] + 1;
                qu.push(v);
            }
    }
    dfs(1, 0, 1);
    init();
    while(q--) {
        int u, v;
        cin >> u >> v;
        cout << min(depth[u] + depth[v] - 2 * depth[lca(u, v)], dis[u] + dis[v]) << '\n';
    }
    return 0;
}