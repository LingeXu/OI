#include <bits/stdc++.h>
#define N 505
using namespace std;
int n, m, cnt = 0, scc_cnt = 0, ans = 0;
int dfn[N], low[N], scc[N], in_deg[N];
bool in_stack[N];
set<int> s, team[N], scc_s[N];
vector<int> graph[N];
stack<int> st;
void tarjan(int u) {
    st.push(u);
    in_stack[u] = true;
    dfn[u] = low[u] = ++cnt;
    for(int v : graph[u]) {
        if(!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if(in_stack[v])    low[u] = min(low[u], dfn[v]);
    }
    if(dfn[u] == low[u]) {
        scc_cnt++;
        while(true) {
            int x = st.top();
            st.pop();
            in_stack[x] = false;
            scc[x] = scc_cnt;
            team[scc_cnt].insert(x);
            if(x == u)    break;
        }
    }
}
void rebuild() {
    for(int i = 1; i <= n; i++)
        for(int j : graph[i])
            if(scc[i] != scc[j])
                scc_s[scc[i]].insert(scc[j]);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int x;
        cin >> x;
        s.insert(x);
        graph[0].push_back(x);
    }
    for(int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        for(int j = 0; j < a; j++) {
            int idx;
            cin >> idx;
            graph[i].push_back(idx);
        }
    }
    for(int i = 0; i <= n; i++)
        if(!dfn[i])
            tarjan(i);
    rebuild();
    for(int i = 1; i < scc_cnt; i++)
        for(int j : scc_s[i])
            in_deg[j]++;
    for(int i = 1; i < scc_cnt; i++) {
        if(in_deg[i] != 0)    continue;
        
        //cout << i << '\n';
        
        bool ok = false;
        for(int j : team[i]) {
            
            //cout << j << '\n';
            
            if(s.find(j) != s.end()) {
                ok = true;
                ans++;
                break;
            }
        }
        if(!ok) {
            cout << -1;
            return 0;
        }
    }
    cout << ans;
    return 0;
}