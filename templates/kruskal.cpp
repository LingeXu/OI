struct edge {
    int u, v, w;
};
bool cmp(edge x, edge y) {
    return x.w < y.w;
}
vector<edge> graph;
int fa[N];
int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void unite(int x, int y) {
    int rx = find(x), ry = find(y);
    if(rx != ry)    fa[rx] = ry;
}
int kruskal() {
    for(int i = 1; i <= n; i++)
        fa[i] = i;
    sort(graph.begin(), graph.end(), cmp);
    int ans = 0, cnt = 0;
    for(auto& e : graph) {
        if(find(e.u) == find(e.v))  continue;
        else {
            unite(e.u, e.v);
            cnt++;
            ans += e.w;
        }
        if(cnt == n - 1)    return ans;
    }
    return -1;  //不连通
}