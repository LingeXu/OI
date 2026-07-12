#include <bits/stdc++.h>
#define N 10010
const int MOD = 10000;
typedef long long ll;
using namespace std;
int n, m, s, t0, t1, cnt = 0;
ll total = 0;
vector< pair<int, int> > graph[N];
void dfs(int u, ll time) {
    if(u == t0) {
        cnt++;
        total = (total + time) % MOD;
        return;
    }
    for(auto e : graph[u])
        dfs(e.second, time + e.first);
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
    dfs(s, 0);
    cout << (total + (cnt - 1) * t1) % MOD;
    return 0;
}