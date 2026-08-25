#include <bits/stdc++.h>
#define N 110
typedef long long ll;
using namespace std;
int n;
bool vis[2 * N];
struct edge {
    int type, to, w;
};
vector<edge> graph[N];
vector<int> group1, group2;
void dfs(int u) {
    for(edge e : graph[u]) {
        if(vis[e.to])    continue;
        vis[e.to] = true;
        if(e.type == 0)    group1.push_back(e.w);
        else    group2.push_back(e.w);
        dfs(e.to);
    }
}
void solve() {
    for(int i = 1; i <= n; i++)    vis[i] = false;
    for(int i = 1; i <= n; i++)    graph[i].clear();
    group1.clear();
    group2.clear();
    for(int i = 0; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edge e1 = {0, v, w};
        edge e2 = {1, u, w};
        graph[u].push_back(e1);
        graph[v].push_back(e2);
    }
    if(graph[1][1].type == 0)   group2.push_back(graph[1][1].w);
    else  group1.push_back(graph[1][1].w);
    vis[1] = true;
    dfs(1);
     
    /*for(int i = 0; i < (int)group1.size(); i++)    cout << group1[i] << ' ';
    cout << '\n';
    for(int i = 0; i < (int)group2.size(); i++)    cout << group2[i] << ' ';
    cout << '\n';*/
     
    int ans1 = 0, ans2 = 0;
    for(int i = 0; i < (int)group1.size(); i++)    ans1 += group1[i];
    for(int i = 0; i < (int)group2.size(); i++)    ans2 += group2[i];
    cout << min(ans1, ans2) << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin >> n)    solve();
    return 0;
}
