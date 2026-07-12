#include <bits/stdc++.h>
#define N 4040
#define M 200020
using namespace std;
int n, m, cnt = 0, scc_cnt = 0;
int dfn[2 * N], low[2 * N], team[2 * N];
bool instack[2 * N], vis[2 * N];
map<string, int> mp;
vector<int> graph[2 * N];
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
    if(dfn[u] == low[u]) {
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
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        string husband, wife;
        cin >> husband >> wife;
        int u = 2 * i - 1, v = 2 * i;
        mp[husband] = u;
        mp[wife] = v;
        graph[u].push_back(v);
    }
    cin >> m;
    for(int i = 1; i <= m; i++) {
        string man, woman;
        cin >> man >> woman;
        int u = mp[man], v = mp[woman];
        graph[v].push_back(u);
    }
    for(int i = 1; i <= 2 * n; i++) 
        if(!vis[i])
            tarjan(i);
    for(int i = 1; i <= n; i++) {
        if(team[2 * i - 1] == team[2 * i])
            cout << "Unsafe" << '\n';
        else    cout << "Safe" << '\n';
    }
    return 0;
}