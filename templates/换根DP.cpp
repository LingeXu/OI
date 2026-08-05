void dfs1(int u, int fa) {
    sz[u] = 1;
    dp[u] = 0;
    for(int v : graph[u]) {
        if(v == fa)
            continue;
        dfs1(v, u);
        sz[u] += sz[v];
        dp[u] += (dp[v] + sz[v]);
    }
}
    ans[root] = dp[root];
void dfs2(int u, int fa) {
    for(int v : graph[u]) {
        if(v == fa)
            continue;
        ans[v] = ans[u] - sz[v] + (n - sz[v]);
        dfs2(v, u);
    }
}