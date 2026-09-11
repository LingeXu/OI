#include <bits/stdc++.h>
#define N 200020
#define K 200020
using namespace std;
int n, m, k, q;
bool win = false;
int a[K];
int max_id[N][N], min_id[N][N];
bool has_odd_edge[N][N], has_even_edge[N][N];
vector<int> path[N];
bool has_route(int u, int v) {
    if(u >= v)  return false;
    int start = a[u];
    int end = a[v];
    if((v - u) & 1) 
        return has_odd_edge[start][end];
    return has_even_edge[start][end];
}
void build(int l, int r) {
    for(int i = l; i <= r; i++)
        for(int j = l; j <= r; j++)
            if(has_route(i, j) && max_id[i][j] <= r && min_id[i][j] >= l)
                path[i].push_back(j);
}
bool dfs(int u, int step) {
    bool have_nx_step = false;
    for(int v : path[u]) {
        have_nx_step = true;
        win |= dfs(v, step + 1);
    }
    if(!have_nx_step)
        win = step & 1;
    return win;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k >> q;
    memset(max_id, -1, sizeof(max_id));
    memset(min_id, 0x3f, sizeof(min_id));
    for(int i = 1; i <= n; i++) {
        has_even_edge[i][i] = true;
        max_id[i][i] = i;
        min_id[i][i] = i;
    }
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        has_odd_edge[u][v] = true;
        has_odd_edge[v][u] = true;
        max_id[u][v] = max(u, v);
        min_id[u][v] = min(u, v);
        max_id[v][u] = max(u, v);
        min_id[v][u] = min(u, v);
    }
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(!has_even_edge[i][j]) {
                    has_even_edge[i][j] = (has_odd_edge[i][k] && has_odd_edge[k][j]) || (has_even_edge[i][k] && has_even_edge[k][j]);
                    max_id[i][j] = max(max_id[i][k], max_id[k][j]);
                    min_id[i][j] = min(min_id[i][k], min_id[k][j]);
                }
                if(!has_odd_edge[i][j]) {
                    has_odd_edge[i][j] = (has_even_edge[i][k] && has_odd_edge[k][j]) || (has_odd_edge[i][k] && has_even_edge[k][j]);
                    max_id[i][j] = max(max_id[i][k], max_id[k][j]);
                    min_id[i][j] = min(min_id[i][k], min_id[k][j]);
                }
            }
        }
    }
    for(int i = 1; i <= k; i++) 
        cin >> a[i];
    for(int i = 1; i <= q; i++) {
        for(int j = 1; j <= n; j++)
            path[j].clear();
        int l, r;
        cin >> l >> r;
        build(l, r);
        win = false;
        if(dfs(l, 0)) 
            cout << "Stark" << '\n';
        else
            cout << "Fern" << '\n';
    }
    return 0;
}