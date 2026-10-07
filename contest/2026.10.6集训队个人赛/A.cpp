#include <bits/stdc++.h>
using namespace std;
#define N 2005
int mx_id;
vector<int> graph[N];
int degree[N];
void dfs(int u, int fa) {
    for(int v : graph[u]) {
        if(v == fa)
            continue;
        cout << mx_id << ' ' << u << ' ' << v << '\n';
        dfs(v, u);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, mx_deg = 0;
    mx_id = -1;
    cin >> n;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }
    for(int i = 1; i <= n; i++) {
        if(degree[i] > mx_deg) {
            mx_deg = degree[i];
            mx_id = i;
        }
    }

    cout << n - 1 - mx_deg << '\n';
    for(int v : graph[mx_id])
        dfs(v, mx_id);
    return 0;
}