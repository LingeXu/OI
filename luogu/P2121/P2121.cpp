#include <bits/stdc++.h>
#define N 100010
#define M 100010
using namespace std;
int n, m, k, id = 0, ans = 0;
int fa[N];
struct edge {
    int from, to, val;
} e[M];
bool cmp(edge x, edge y) {
    return x.val > y.val;
}
int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
void unite(int& id, int& ans, int& k) {
    int x = e[id].from, y = e[id].to;
    int rx = find(x), ry = find(y);
    if(rx != ry) {
        fa[rx] = ry;
        ans += e[id].val;
        k = k - 1;
    }
    id = id + 1;
}
vector< pair<int, int> > graph[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
        fa[i] = i;
    for(int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({w, v});
        e[id++] = {u, v, w};
    }
    sort(e, e + id, cmp);
    int now = 0;
    while(k > 0) {
        //cout << now << ' ' << ans << ' ' << k << '\n';
        unite(now, ans, k);
    }
    cout << ans;
    return 0;
}