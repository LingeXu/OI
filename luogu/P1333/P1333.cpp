#include <bits/stdc++.h>
#define N 500001
using namespace std;
int idx = 0, cnt = 0, scc_cnt = 0, even_deg_cnt = 0, start;
int deg[N], in_deg[N], low[N], dfn[N];
bool in_stack[N];
map<string, int> mp;
vector<int> graph[N];
stack<int> s;
/*void topo_sort() {
    queue<int> q;
    for(int i = 1; i <= idx; i++)
        if(in_deg[i] == 0)
            q.push(i);
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        for(int j : graph[x])
            if(--in_deg[j] == 0)
                q.push(j);
    }
}*/
bool tarjan(int u) {
    low[u] = dfn[u] = ++cnt;
    s.push(u);
    in_stack[u] = true;
    for(int j : graph[u]) {
        if(!dfn[j]) {
            tarjan(j);
            low[u] = min(low[u], low[j]);
        }
        else if(in_stack[j])
            low[u] = min(low[u], dfn[j]);
    }
    if(low[u] == dfn[u]) {
        while(1) {
            int x = s.top();
            s.pop();
            in_stack[x] = false;
            if(++scc_cnt > 1)
                return false;
            if(x == u)
                break;
        }
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s1, s2;
    while(cin  >> s1 >> s2) {
        if(!mp[s1])
            mp[s1] = ++idx;
        if(!mp[s2])
            mp[s2] = ++idx;
        graph[mp[s1]].push_back(mp[s2]);
        deg[mp[s1]]++;
        deg[mp[s2]]++;
        in_deg[mp[s2]]++;
    }
    for(int i = 1; i <= idx; i++)
        if(in_deg[i] == 0)
            start = i;
    if(!tarjan(start)) {
        cout << "Impossible";
        return 0;
    }
    for(int i = 1; i <= idx; i++)
        if(deg[i] & 1)
            even_deg_cnt++;
    if(even_deg_cnt != 0 && even_deg_cnt != 2)
        cout << "Impossible";
    else
        cout << "Possible";
    return 0;
}