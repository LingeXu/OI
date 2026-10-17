//树形背包: 树上依赖选择, dp[u][j] = u 的子树中选 j 个且必选 u 的最大价值
//依赖关系: 选子必选父; dp[u][0] = 0 表示空集
//需预定义: int sz[N];  dp 初始全 0
//j 从 1 开始并倒序 = 01 背包, 防止同一子树 v 被重复计入; 复杂度 O(n * m)

void dfs(int u, int fa) {
    sz[u] = 1;
    dp[u][1] = w[u];                                     //只选 u
    for(int v : graph[u]) {
        if(v == fa)    continue;
        dfs(v, u);
        for(int j = sz[u]; j >= 1; j--)                  //已合并部分选 j 个(含 u)
            for(int k = 1; k <= sz[v] && j + k <= m; k++)
                dp[u][j + k] = max(dp[u][j + k], dp[u][j] + dp[v][k]);
        sz[u] += sz[v];
    }
}
//答案: dp[root][m](必须选满)或 max(dp[root][1..m])(至多)
//变体: 边权版本把 w[u] 换成 w[边(u,fa)]; 无依赖版本(选子树任意点)才需要 j 从 0 开始

