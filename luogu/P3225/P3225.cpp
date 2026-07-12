#include <bits/stdc++.h>
#define N 505
#define M 1010
using namespace std;
int n, m = 0, timer = 0, dcc_cnt = 0;
int dfn[2 * N], low[2 * N];
bool cut[2 * N];
vector<int> graph[2 * N];
vector<int> dcc[2 * N];
stack<int> s;
void tarjan(int u, int root) {
    dfn[u] = low[u] = ++timer;
    s.push(u);
    instack[u] = true;
    int child = 0;
    for(int v : graph[u]) {
        if(!dfn[v]) {
            child++;
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] >= dfn[u]) {
                if(u != root)   cut[u] = true;
                dcc_cnt++;
                while(!s.empty()) {
                    int x = s.top();
                    s.pop();
                    instack[x] = false;
                    dcc[dcc_cnt].push_back(x);
                    if(x == u)
                        break;
                }
            }
        }
        else if(instack[v])
            low[u] = min(low[u], dfn[v]);
    }
    if(u == root && child >= 2)
        cut[u] = true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while(cin >> n && n != 0) {
        for(int i = 1; i <= m; i++)  graph[i].clear();
        for(int i = 1; i <= n; i++) {
            int s, t;
            cin >> s >> t;
            m = max(m, max(s, t));
            graph[s].push_back(t);
            graph[t].push_back(s);
        }
        for(int i = 1; i <= m; i++)
            if(!dfn[i])
                tarjan(i, i);
    }
    return 0;
}