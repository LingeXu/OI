void dfs1(int u, int fa) {
    sz[u] = 1;
    dp[u] = 0;  // 子树内所有节点到u的距离之和
    for(int v : graph[u]) {
        if(v == fa)
            continue;
        dfs1(v, u);
        sz[u] += sz[v];
        dp[u] += (dp[v] + sz[v]);
    }
}
//主函数中调用: ans[root] = dp[root];
void dfs2(int u, int fa) {
    for(int v : graph[u]) {
        if(v == fa)
            continue;
        ans[v] = ans[u] - sz[v] + (n - sz[v]);
        dfs2(v, u);
    }
}