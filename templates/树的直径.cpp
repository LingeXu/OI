int dfs(int u, int fa) {
    int max1 = 0, max2 = 0;
    for(int v : graph[u]) {
        if(v == fa)
            continue;
        int d = dfs(v, u) + 1;
        if(d > max1) {
            max2 = max1;
            max1 = d;
        }
        else if(d > max2)   max2 = d;
    }
    ans = max(ans, max1 + max2);
    return max1;
}