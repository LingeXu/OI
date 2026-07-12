#include <bits/stdc++.h>
#define N 10010
const int MOD = 10000;
typedef long long ll;
using namespace std;
int n, m, s, t0, t1;
int in_deg[N], cnt[N], ans[N];
vector< pair<int, int> > graph[N];
void topo_sort() {
    for(int i = 1; i <= n; i++)
        for(auto e : graph[i])
            in_deg[e.second]++;
    cnt[s] = 1;
    ans[s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        if(x == t0)
            return;
        for(auto e : graph[x]) {
            cnt[e.second] = (cnt[e.second] + cnt[x]) % MOD;
            ans[e.second] = (ans[e.second] + ans[x] + cnt[x] * e.first) % MOD;
            if(--in_deg[e.second] == 0)
                q.push(e.second);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> s >> t0 >> t1;
    for(int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({w, v});
    }
    topo_sort();
    cout << (ans[t0] + (cnt[t0] - 1) * t1) % MOD;
    return 0;
}