//法一: 树上dp
int dfs(int u, int fa) {
    int max1 = 0, max2 = 0;
    for(auto& e : graph[u]) {
        int w = e.first, v = e.second;
        if(v == fa)
            continue;
        int d = dfs(v, u) + w;
        if(d > max1) {
            max2 = max1;
            max1 = d;
        }
        else if(d > max2)   max2 = d;
    }
    ans = max(ans, max1 + max2);
    return max1;
}

//法二: 两次dfs
void dfs(int u, int fa, int d) {
    parent[u] = fa;
    dis[u] = d;
    if(d > dis[far])    far = u;
    for(auto& e : graph[u]) {
        int w = e.first, v = e.second;
        if(v == fa) 
            continue;
        dfs(v, u, d + w);
    }
}

int get_diameter() {
    far = 1;
    dfs(1, 0, 0);
    node1 = far;
    far = node1;
    dfs(node1, 0, 0);
    node2 = far;
    return dis[far];
}