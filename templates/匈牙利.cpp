//二分图: 染色判定 + 最大匹配(匈牙利算法)

//染色判定: 无向图能否分成两部, 使每条边两端颜色不同 <=> 无奇环
//需预定义: vector<int> graph[N];  int color[N];  (-1 表示未染色)
bool dfs_color(int u, int c) {
    color[u] = c;
    for(int v : graph[u]) {
        if(color[v] == -1) {
            if(!dfs_color(v, c ^ 1))    return false;
        }
        else if(color[v] == c)    return false;    //同色相邻, 不是二分图
    }
    return true;
}
//调用: memset(color, -1, sizeof(color)); 对每个未染色点 dfs_color(i, 0)

//匈牙利算法: 二分图最大匹配, O(nm)
//左部 n 个点, 右部 m 个点, graph 只存"左部 -> 右部"的边
//需预定义: int match[N];  bool vis[N];   (match[v] = 匹配到 v 的左部点, 0 表示未匹配)
bool dfs_match(int u) {
    for(int v : graph[u]) {
        if(vis[v])    continue;
        vis[v] = true;
        if(match[v] == 0 || dfs_match(match[v])) {
            match[v] = u;
            return true;
        }
    }
    return false;
}
int hungarian() {
    memset(match, 0, sizeof(match));
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof(vis));
        if(dfs_match(i))    ans++;
    }
    return ans;
}

//配套结论(König 定理):
//1. 最大匹配数 = 最小点覆盖数(选最少的点覆盖所有边)
//2. 最大独立集(最多的点互不相邻) = 总点数 - 最小点覆盖
//3. DAG 最小路径覆盖(不相交路径覆盖所有点) = n - 二分图最大匹配(拆点后)
