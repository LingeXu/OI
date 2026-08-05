//从树上选取若干个互不相邻的结点, 求它们的最大权值和
void dfs(int u, int fa) {
    dp[u][0] = 0;       //不选u
    dp[u][1] = w[u];    //选u
    for(int v : graph[u]) {
        if(v == fa)
            continue;
        dfs(v, u);
        dp[u][0] += max(dp[v][0], dp[v][1]);
        dp[u][1] += dp[v][0];
    }
}