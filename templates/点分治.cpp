//点分治: 统计树上路径信息(长度为 k 的路径条数等), O(n log n)
//核心: 每次取重心, 统计"经过重心"的路径, 再递归到各连通块
//需预定义: vector< pair<int, int> > graph[N];  bool vis[N];  int sz[N];

void get_sz(int u, int par) {            //求子树大小(在去掉已处理重心后的连通块内)
    sz[u] = 1;
    for(auto& e : graph[u]) {
        int v = e.second;
        if(v == par || vis[v])    continue;
        get_sz(v, u);
        sz[u] += sz[v];
    }
}

int get_centroid(int u, int par, int total) {   //找重心: 最大子树 <= total/2
    for(auto& e : graph[u]) {
        int v = e.second;
        if(v == par || vis[v])    continue;
        if(sz[v] > total / 2)    return get_centroid(v, u, total);
    }
    return u;
}

void dfs_dist(int u, int par, int d) {   //收集 u 连通块内所有点到重心的距离
    dists.push_back(d);
    for(auto& e : graph[u]) {
        int v = e.second;
        if(v == par || vis[v])    continue;
        dfs_dist(v, u, d + e.first);
    }
}

void solve(int u) {
    get_sz(u, 0);
    int c = get_centroid(u, 0, sz[u]);
    vis[c] = true;
    //--- 统计经过重心 c 的路径 ---
    //维护全局桶 mp: 之前处理过的子树中"距 c 为 d"的点数
    //对每个子树: 先查(与桶中配对)再加(放入桶), 避免同一子树内部错误配对
    //例: 距离 == k 的路径数: 对 dists 中每个 d 查 mp[k - d]
    //--- 递归处理剩余连通块 ---
    for(auto& e : graph[c]) {
        int v = e.second;
        if(!vis[v])    solve(v);
    }
}
//配套: 树上路径统计先想点分治/树剖/倍增; 点分治配合桶, 计数类注意"先查后加"防同子树
