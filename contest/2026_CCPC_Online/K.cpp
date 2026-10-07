#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 200005
const int MOD = 998244353;
int n, m, t;
string s;
vector< pair<int, int> > graph[N], rgraph[N];
int out_deg[N], cnt[N], dist[N], e[N];
void dijkstra() {
    priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;
    pq.push(make_pair(0, t));
    dist[t] = 0;
    while(!pq.empty()) {
        auto x = pq.top();
        pq.pop();
        for(auto e : rgraph[x.second]) {
            if(dist[e.second] > dist[x.second] + e.first) {
                dist[e.second] = dist[x.second] + e.first;
                pq.push(make_pair(dist[e.second], e.second));
            }
        }
    }
}
void dfs1(int u) {
    if(cnt[u] != 0)
        return;
    for(auto edge : graph[u]) {
        if(dist[u] == dist[edge.second] + edge.first) {
            dfs1(edge.second); 
            cnt[u] = (cnt[u] + cnt[edge.second]) % MOD;
        }
    }
}
int q_pow(int a, int p) {
    int base = a % MOD;
    int res = 1;
    while(p > 0) {
        if(p & 1)   res = res * base % MOD;
        p >>= 1;
        base = base * base % MOD;
    }
    return res;
}
int inv(int x) {
    return q_pow(x, MOD - 2);
}
int dfs2(int u) {
    if(e[u] != -1)
        return e[u];
    int res = 0;
    if(s[u - 1] == '0') {
        for(auto edge : graph[u]) 
            res = (res + edge.first % MOD + dfs2(edge.second)) % MOD;
        return e[u] = res * inv(out_deg[u]) % MOD;
    }
    else {
        for(auto edge : graph[u])
            if(dist[u] == dist[edge.second] + edge.first)
                res = (res+ (edge.first % MOD + dfs2(edge.second)) * cnt[edge.second] % MOD) % MOD;
        return e[u] = res * inv(cnt[u]) % MOD;
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> t >> s;
    for(int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(w, v));
        rgraph[v].push_back(make_pair(w, u));
        out_deg[u]++;
    }
    memset(dist, 0x3f, sizeof(dist));
    dijkstra();
    memset(cnt, 0, sizeof(cnt));
    cnt[t] = 1;
    for(int i = 1; i <= n; i++)
        dfs1(i);
    memset(e, -1, sizeof(e));
    e[t] = 0;
    for(int i = 1; i <= n; i++)
        cout << dfs2(i) << ' ';

    /*cout << "Test:\n";
    for(int i = 1; i <= n; i++)
        cout << "dist = " << dist[i] << ", cnt = " << cnt[i] << '\n';*/
    
    return 0;
}