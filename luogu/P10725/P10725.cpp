#include <bits/stdc++.h>
#define N 100010
#define INF 0x3f3f3f3f
using namespace std;
int n, ans = -INF;
int color[N], dp[N][2];
vector<int> graph[N];
void dfs(int u, int fa) {
    dp[u][0] = dp[u][1] = -INF;
    dp[u][color[u]] = 0;
    for(int v : graph[u]) {
        if(v == fa)
            continue;
        dfs(v, u);
        ans = max(ans, max(dp[u][0] + dp[v][1] + 1, dp[u][1] + dp[v][0] + 1));
        dp[u][0] = max(dp[u][0], dp[v][0] + 1);
        dp[u][1] = max(dp[u][1], dp[v][1] + 1);
    }
} 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> color[i];
    for(int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    memset(dp, -0x3f, sizeof(dp));
    dfs(1, 0);
    cout << ans;
    return 0;
}