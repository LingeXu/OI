#include <bits/stdc++.h>
#define N 100010
#define K 22
using namespace std;
int n, k;
int c[N], dp[N][K], ans[N];
vector<int> graph[N];
void init(int u, int father) {
    dp[u][0] = c[u];
    for(int to : graph[u]) {
        if(to != father) {
            init(to, u);
            for(int i = 1; i <= k; i++) 
                dp[u][i] += dp[to][i - 1];
        }
    }
}
void floyd() {
    for(int dist = 0; dist <= k; dist++) 
        for(int u = 1; u <= n; u++)
            for(int v = 1; v <= n; v++)
                dp[u][v] = min(dp[u][v], dp[u][dist] + dp[v][dist]);
}
void dfs(int u, int father) {
    for(int i = 0; i <= k; i++)
        ans[u] += dp[u][i];
    int backup_u[K];
    for(int v : graph[u]) {
        if(v != father) {
            int backup_v[K];
            for(int i = 0; i <= k; i++) {
                backup_u[i] = dp[u][i];
                backup_v[i] = dp[v][i];
            }
            for(int i = 1; i <= k; i++) 
                dp[u][i] -= dp[v][i - 1];
            for(int i = 1; i <= k; i++)
                dp[v][i] += dp[u][i - 1];
            dfs(v, u);
            for(int i = 0; i <= k; i++) {
                dp[u][i] = backup_u[i];
                dp[v][i] = backup_v[i];
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i = 1; i <= n; i++)
        cin >> c[i];
    init(1, 0);
    dfs(1, 0);
    for(int i = 1; i <= n; i++)
        cout << ans[i] << '\n';
    return 0;
}