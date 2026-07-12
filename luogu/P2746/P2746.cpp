#include <bits/stdc++.h>
#define N 110
using namespace std;
int n, cnt = 0, scc_cnt = 0, ans1 = 0, ans2 = 0, start = -1;
int dfn[N], low[N], team[N], in_deg[N], out_deg[N];
bool instack[N], vis[N];
vector<int> graph[N], g[N];
stack<int> s;
void tarjan(int u) {
    vis[u] = true;
    dfn[u] = low[u] = ++cnt;
    s.push(u);
    instack[u] = true;
    for(int v : graph[u]) {
        if(!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if(instack[v])
            low[u] = min(low[u], dfn[v]);
    }
    if(low[u] == dfn[u]) {
        while(!s.empty()) {
            int x = s.top();
            s.pop();
            instack[x] = false;
            team[x] = scc_cnt;
            if(x == u) {
                scc_cnt++;
                break;
            }
        }
    }
}
void build_and_solve() {
    for(int i = 1; i <= n; i++) {
        for(int to : graph[i]) {
            if(team[i] != team[to]) {
                g[team[i]].push_back(team[to]);
                in_deg[team[to]]++;
                out_deg[team[i]]++;
            }
        }
    }
    for(int i = 0; i < scc_cnt; i++) {

        //cout << in_deg[i] << ' ' << out_deg[i] << '\n';

        if(in_deg[i] == 0) 
            ans1++;
        if(out_deg[i] == 0)
            ans2++;
    }
    cout << ans1 << '\n';
    if(scc_cnt == 1) {
        cout << 0;
        return;
    }
    cout << max(ans1, ans2);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int to;
        while(cin >> to && to != 0) 
            graph[i].push_back(to);
    }
    for(int i = 1; i <= n; i++)
        if(!vis[i])
            tarjan(i);
    build_and_solve();
    return 0;
}