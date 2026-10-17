#include <bits/stdc++.h>
using namespace std;
#define N 100005
int n, m, q, cnt = 0, scc_cnt = 0;
vector<int> graph[N], g[N];
int dfn[N], low[N], team[N], depth[N];
stack<int> s;
bool in_stack[N];
void tarjan(int u, int fa) {
    dfn[u] = low[u] = ++cnt;
    s.push(u);
    in_stack[u] = true;
    for(int v : graph[u]) {
        if(v == fa)
            continue;
        if(!dfn[v]) {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
        }
        else if(in_stack[v])    low[u] = min(low[u], dfn[v]);
    }
    if(dfn[u] == low[u]) {
        ++scc_cnt;
        while(true) {
            int x = s.top();
            s.pop();
            in_stack[x] = false;
            team[x] = scc_cnt;
            if(x == u)  break;
        }
    }
}
void dfs(int u, int fa) {
    depth[u] = depth[fa] + 1;
    for(int v : g[u]) {
        if(v == fa)
            continue;
        dfs(v, u);
    }
}
/*void tarjan(int u) {
    dfn[u] = low[u] = ++timer;
    stk[++top] = u;
    inStk[u] = true;

    for (int v : g[u]) {
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (inStk[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }

    if (dfn[u] == low[u]) {
        ++sccCnt;
        while (true) {
            int v = stk[top--];
            inStk[v] = false;
            scc[v] = sccCnt;
            if (v == u) break;
        }
    }
}*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> q;
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector< vector<bool> > has_edge(n + 1, vector<bool>(n + 1, false));
    tarjan(1, 0);
    for(int i = 1; i <= n; i++) {
        for(int j : graph[i]) {
            if(j < i)   continue;
            if(team[i] == team[j])
                continue;
            if(has_edge[team[i]][team[j]])
                continue;
            g[team[i]].push_back(team[j]);
            g[team[j]].push_back(team[i]);
            has_edge[team[i]][team[j]] = true;
        }
    }
    depth[0] = 0;
    dfs(1, 0);

    /*for(int i = 1; i <= n; i++)
        cout << "i = " << i << ", team = " << team[i] << '\n';*/

    /*while(q--) {
        int u, v;
        cin >> u >> v;
        if(u == v) {
            cout << 0 << '\n';
            continue;
        }
        if(team[u] == team[v]) {
            cout << 0 << '\n';
            continue;
        }
        cout << abs(depth[team[u]] - depth[team[v]]) - 1 << '\n';
    }*/
    return 0;
}