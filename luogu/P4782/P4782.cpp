#include <bits/stdc++.h>
#define N 1000010
#define M 1000010
using namespace std;
int n, m, cnt = 0, scc_cnt = 0;
int dfn[2 * N], low[2 * N], scc[2 * N];
bool in_stk[2 * N];
struct cond {
    int i, a, j, b;
} c[M];
vector<int> graph[2 * N];
stack<int> stk;
void tarjan(int u) {
    stk.push(u);
    in_stk[u] = true;
    dfn[u] = low[u] = ++cnt;
    for(int v : graph[u]) {
        if(!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if(in_stk[v])  low[u] = min(low[u], dfn[v]);
    }
    if(dfn[u] == low[u]) {
        scc_cnt++;
        while(true) {
            int x = stk.top();
            stk.pop();
            in_stk[x] = false;
            scc[x] = scc_cnt;
            if(x == u)  break;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int idx = 0; idx < m; idx++) {
        cin >> c[idx].i >> c[idx].a >> c[idx].j >> c[idx].b;
        if(c[idx].a == 0 && c[idx].b == 0) {
            graph[c[idx].i + n].push_back(c[idx].j);
            graph[c[idx].j + n].push_back(c[idx].i);
        }
        else if(c[idx].a == 0 && c[idx].b == 1) {
            graph[c[idx].i + n].push_back(c[idx].j + n);
            graph[c[idx].j].push_back(c[idx].i);
        }
        else if(c[idx].a == 1 && c[idx].b == 0) {
            graph[c[idx].i].push_back(c[idx].j);
            graph[c[idx].j + n].push_back(c[idx].i + n);
        }
        else {
            graph[c[idx].i].push_back(c[idx].j + n);
            graph[c[idx].j].push_back(c[idx].i + n);
        }
    }
    for(int i = 1; i <= 2 * n; i++)
        if(!dfn[i])
            tarjan(i);
    bool have_solution = true;
    for(int i = 1; i <= n; i++) {
        if(scc[i] == scc[i + n]) {
            have_solution = false;
            break;
        }
    }
    if(!have_solution) 
        cout << "IMPOSSIBLE";
    else {
        cout << "POSSIBLE\n";
        for(int i = 1; i <= n; i++) {
            if(scc[i] < scc[i + n])
                cout << "0 ";
            else    cout << "1 ";
        }
    }
    return 0;
}