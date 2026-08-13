#include <bits/stdc++.h>
#define N 100010
typedef long long ll;
using namespace std;
int n, m, x, cnt = 0, scc_cnt = 0;
int dfn[N], low[N], scc[N], in_deg[N];
ll ans[N], method[N];
bool in_stack[N];
vector<int> graph[N], g[N];
stack<int> st;
set<int> team[N];
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
            team[scc_cnt].insert(x);
            scc[x] = scc_cnt;
            if(x == u)    break;
        }
    }
}
pair<ll, ll> dfs(int u) {
    if(ans[u] != 0 && method[u] != 0)
        return make_pair(ans[u], method[u]);
    ll res1 = 1LL * (int)team[u].size(), res2 = 1;
    for(int v : g[u]) {
        if(1LL * (int)team[u].size() + dfs(v).first > res1) {
            res1 = 1LL * (int)team[u].size() + dfs(v).first;
            res2 = dfs(v).second % x;
        }
        else if(1LL * (int)team[u].size() + dfs(v).first == res1)
            res2 = (res2 + dfs(v).second) % x;
        else    continue;
    }
    ans[u] = res1, method[u] = res2;
    return make_pair(res1, res2);
}
void build() {
    vector< unordered_set<int> > has_edge(scc_cnt + 1);
    for(int i = 1; i <= n; i++) {
        for(int j : graph[i]) {
            if(scc[i] != scc[j]) {
                if(has_edge[scc[i]].find(scc[j]) == has_edge[scc[i]].end()) {
                    has_edge[scc[i]].insert(scc[j]);
                    g[scc[i]].push_back(scc[j]);
                    in_deg[scc[j]]++;
                }
            }
        }
    }
}
void solve() {
    ll k = 0, c = 0;
    for(int i = 1; i <= scc_cnt; i++) 
        if(in_deg[i] == 0)
            k = max(k, dfs(i).first);
    for(int i = 1; i <= scc_cnt; i++)
        if(in_deg[i] == 0 && ans[i] == k)
            c = (c + method[i]) % x;
    cout << k << '\n';
    cout << c;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> x;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    for(int i = 1; i <= n; i++)
        if(!dfn[i])
            tarjan(i);
    build();
    
    /*for(int i = 1; i <= n; i++)
        cout << scc[i] << ' ';
    cout << '\n';
    
    for(int i = 1; i <= scc_cnt; i++)
        cout << (int)team[i].size() << ' ';
    cout << '\n';
    
    for(int i = 1; i <= scc_cnt; i++)
        cout << in_deg[i] << ' ';
    cout << '\n';*/
    
    solve();
    //cout << '\n';
    
    /*for(int i = 1; i <= scc_cnt; i++)
        cout << ans[i] << ' ';
    cout << '\n';
    
    for(int i = 1; i <= scc_cnt; i++)
        cout << method[i] << ' ';
    cout << '\n';*/
    
    return 0;
}