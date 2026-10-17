#include <bits/stdc++.h>
using namespace std;
#define N 200005
int t, n;
vector<int> graph[N];
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++)
        graph[i].clear();
    vector<int> in_deg(n + 1);
    for(int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
        in_deg[u]++;
        in_deg[v]++;
    }
    int leaf_cnt = 0;
    for(int i = 1; i <= n; i++)
        if(in_deg[i] == 1)
            leaf_cnt++;
    int ans = n;
    for(int i = 1; i <= n; i++) {
        int one = 0;
        for(int v : graph[i])
            if((int)graph[v].size() == 1)
                one++;
        ans = min(ans, leaf_cnt - one - (in_deg[i] == 1 ? 1 : 0));
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--)  solve();
    return 0;
}