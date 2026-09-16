#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 200020
int t, n;
vector<int> graph[N], a(N), depth(N), val(N), cost(N), max_depth(N), second_depth(N), change(N);
void dfs(int u, int fa) {
    val[u] = a[u], cost[u] = 0;
    depth[u] = depth[fa] + 1;
    max_depth[u] = depth[u];
    second_depth[u] = -1;
    change[u] = 0;
    for(int v : graph[u]) {
        if(v == fa)
            continue;
        dfs(v, u);
        val[u] += val[v];
        cost[u] += cost[v] + val[v];
        if(max_depth[v] >= max_depth[u]) {
            second_depth[u] = max_depth[u];
            max_depth[u] = max_depth[v];
            continue;
        }
        if(max_depth[v] < max_depth[u] && max_depth[v] >= second_depth[u]) {
            second_depth[u] = max_depth[v];
            continue;
        }
    }
    int child_count = 0;
    for(int v : graph[u]) {
        if(v == fa)
            continue;
        child_count++;
    }
    if(child_count == 0) {
        change[u] = 0;
        return;
    }
    if(child_count == 1) {
        if(graph[u][0] == fa) {
            change[u] = change[graph[u][1]];
            return;
        }
        else {
            change[u] = change[graph[u][0]];
            return;
        }
    }
    for(int v : graph[u]) {
        if(v == fa)
            continue;
        change[u] = max(change[u], change[v]);
        if(max_depth[u] == max_depth[v])
            change[u] = max(change[u], val[v] * (second_depth[u] - depth[u]));
        else    change[u] = max(change[u], val[v] * (max_depth[u] - depth[u]));
    }
}
void solve() {
    cin >> n;
    a.clear();
    depth.clear();
    val.clear();
    cost.clear();
    max_depth.clear();
    second_depth.clear();
    change.clear();
    for(int i = 1; i <= n; i++) 
        graph[i].clear();
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1, 0);
    for(int i = 1; i <= n; i++) 
        cout << cost[i] + change[i] << ' ';
    cout << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--)  solve();
    return 0;
}