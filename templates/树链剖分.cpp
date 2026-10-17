//树链剖分(重链剖分): 树上路径修改/查询转成 O(log n) 段连续的 dfn 区间, 线段树维护
//需预定义: vector<int> graph[N];  int sz[N], dep[N], fa[N], son[N];  int top[N], dfn[N], rnk[N];
//入口: dfs1(root, 0); dfs2(root, root);  之后树上路径 = 若干段 [dfn[top], dfn[u]]

void dfs1(int u, int par) {              //第一遍: 求 sz / dep / fa / son(重儿子)
    sz[u] = 1;
    dep[u] = dep[par] + 1;
    fa[u] = par;
    for(int v : graph[u]) {
        if(v == par)    continue;
        dfs1(v, u);
        sz[u] += sz[v];
        if(sz[v] > sz[son[u]])    son[u] = v;
    }
}

void dfs2(int u, int tp) {               //第二遍: 求 top / dfn, 先走重儿子保证重链 dfn 连续
    top[u] = tp;
    dfn[u] = ++dfn_cnt;
    rnk[dfn[u]] = u;
    if(son[u])    dfs2(son[u], tp);
    for(int v : graph[u])
        if(v != fa[u] && v != son[u])    dfs2(v, v);
}

void path_update(int u, int v, int val) {   //u-v 路径上的点权 +val
    while(top[u] != top[v]) {
        if(dep[top[u]] < dep[top[v]])    swap(u, v);
        seg_update(1, 1, n, dfn[top[u]], dfn[u], val);   //整段重链
        u = fa[top[u]];                  //跳到链顶的父亲
    }
    if(dep[u] > dep[v])    swap(u, v);
    seg_update(1, 1, n, dfn[u], dfn[v], val);
}

ll path_query(int u, int v) {              //u-v 路径上的点权和, 结构与上面相同
    ll res = 0;
    while(top[u] != top[v]) {
        if(dep[top[u]] < dep[top[v]])    swap(u, v);
        res += seg_query(1, 1, n, dfn[top[u]], dfn[u]);
        u = fa[top[u]];
    }
    if(dep[u] > dep[v])    swap(u, v);
    return res + seg_query(1, 1, n, dfn[u], dfn[v]);
}
//配套: 边权版本: 把边权下放为"儿子点权"(dfn 时赋值), 路径操作最后 LCA 处跳过
//      子树操作: 子树 u 对应 dfn 区间 [dfn[u], dfn[u] + sz[u] - 1]
//      线段树数组按 dfn 建树: build 时 a_seg[dfn[i]] = w[i]
