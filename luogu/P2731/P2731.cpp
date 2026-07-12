#include <bits/stdc++.h>
#define U 505
#define V 505
using namespace std;
int m;
int deg[U], has_edge[U][V];
bool exist[U];
vector<int> graph[U];
vector<int> ans;
void dfs(int u) {
    for(int v : graph[u]) {
        if(has_edge[u][v] > 0) {
            has_edge[u][v]--;
            has_edge[v][u]--;
            dfs(v);
        }
    }
    ans.push_back(u);
}
void euler_route() {
    int zero_cnt = 0, start = U;
    for(int i = 1; i < U; i++) {
        if(exist[i] && (deg[i] & 1)) {
            start = min(start, i);
            if(++zero_cnt == 2)
                break;
        }
    }
    if(start == U)
        for(int i = 1; i < U; i++) {
            if(exist[i]) {
                start = i;
                break;
            }
        }
    dfs(start);
    reverse(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> m;
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        exist[u] = exist[v] = true;
        has_edge[u][v]++;
        has_edge[v][u]++;
        deg[u]++;
        deg[v]++;
    }
    for(int i = 1; i < U; i++)
        if(exist[i])
            sort(graph[i].begin(), graph[i].end());
    euler_route();
    return 0;
}