//DSU on tree(树上启发式合并): 对每个节点求"子树内"的统计信息(颜色数等), O(n log n)
//核心: 重儿子的贡献算完保留, 轻儿子子树暴力加一遍; 每个点作为轻子树成员被重算 O(log n) 次
//需预定义: vector<int> graph[N];  int sz[N], son[N];  bool skip[N];  颜色 color[N];
//         int cnt[C];  int distinct;   (以"子树内不同颜色数"为例的统计)

void dfs1(int u, int par) {              //第一遍: 求 sz 与重儿子 son
    sz[u] = 1;
    for(int v : graph[u]) {
        if(v == par)    continue;
        dfs1(v, u);
        sz[u] += sz[v];
        if(sz[v] > sz[son[u]])    son[u] = v;
    }
}

void add_subtree(int u, int par, int val) {   //把 u 子树所有点的颜色按 val(+1 加入 / -1 删除)计入
    if(cnt[color[u]] == 0)    distinct++;     //(统计量换成别的就改这两处, 如求和 distinct += color[u] * val)
    cnt[color[u]] += val;
    if(cnt[color[u]] == 0)    distinct--;
    for(int v : graph[u])
        if(v != par && !skip[v])    add_subtree(v, u, val);
}

void dfs2(int u, int par, bool keep) {
    for(int v : graph[u])                    //先算所有轻儿子, 算完清空贡献
        if(v != par && v != son[u])    dfs2(v, u, false);
    if(son[u]) {
        dfs2(son[u], u, true);               //重儿子贡献保留
        skip[son[u]] = true;                 //下面 add_subtree 时跳过它
    }
    add_subtree(u, par, 1);                  //暴力加入 u 本身与所有轻儿子子树
    skip[son[u]] = false;
    ans[u] = distinct;                       //此时统计的是 u 的整棵子树
    if(!keep)    add_subtree(u, par, -1);    //不留贡献则整体清空
}
//典型: 子树内不同颜色数; 离线回答子树询问(按 dfn 变成区间问题则用莫队/主席树)
