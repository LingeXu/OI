#include <bits/stdc++.h>
using namespace std;
int t, n;
#define int long long
void solve() {
    cin >> n;
    vector<int> graph[n + 1], in_deg(n + 1, 0);
    for(int i = 1; i < n; i++) {
        int u, v, x, y;
        cin >> u >> v >> x >> y;
        if(x <= y) {
            graph[u].push_back(v);
            in_deg[v]++;
        }
        else {
            graph[v].push_back(u);
            in_deg[u]++;
        }
    }
    vector<int> ans(n + 1);
    queue<int> q;
    for(int i = 1; i <= n; i++)
        if(in_deg[i] == 0)
            q.push(i);
    int cur = 1;
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        ans[x] = cur;
        cur++;
        for(int v : graph[x])
            if(--in_deg[v] == 0)
                q.push(v);
    }
    for(int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
    cout << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--)  solve();
    return 0;
}