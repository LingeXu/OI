//LCA 最近公共祖先(倍增) + 树上差分
//需预定义: vector< pair<int, int> > graph[N];   int depth[N], fa[LOG][N];   ll dist[N];
//入口: dfs(root, 0) 预处理; get_lca(u, v) 查询
//树上任意两点距离 = dist[u] + dist[v] - 2 * dist[lca(u, v)]

#define LOG 20                    //需满足 2^LOG > n

void dfs(int u, int par) {
    fa[0][u] = par;
    for(int k = 1; k < LOG; k++)
        fa[k][u] = fa[k - 1][fa[k - 1][u]];
    for(auto& e : graph[u]) {
        int w = e.first, v = e.second;
        if(v == par)    continue;
        depth[v] = depth[u] + 1;
        dist[v] = dist[u] + w;
        dfs(v, u);
    }
}

int get_lca(int u, int v) {
    if(depth[u] < depth[v])    swap(u, v);
    int diff = depth[u] - depth[v];
    for(int k = 0; k < LOG; k++)
        if(diff >> k & 1)    u = fa[k][u];       //抬到同一深度
    if(u == v)    return u;
    for(int k = LOG - 1; k >= 0; k--)
        if(fa[k][u] != fa[k][v]) {               //一起往上跳, 跳到 lca 的儿子
            u = fa[k][u];
            v = fa[k][v];
        }
    return fa[0][u];
}

//树上差分: "u 到 v 的路径整体 +x, 最后问每个点/每条边的值"
//需预定义: ll dif[N];
//点差分: dif[u] += x; dif[v] += x; dif[lca] -= x; dif[fa[0][lca]] -= x;
//边差分: dif[u] += x; dif[v] += x; dif[lca] -= 2 * x;   (dif[u] 表示 u 到父节点的边)
//最后自底向上: dif[fa[u]] += dif[u](从深到浅遍历或再 dfs 一遍)
//边差分把点权挂到边上: 节点 u 到父节点的边对应 dif[u], lca 处抵消

//配套: k 级祖先 = 上面的抬深度写法;  倍增还能求"路径上的第 k 个点"和"树剖前处理"
