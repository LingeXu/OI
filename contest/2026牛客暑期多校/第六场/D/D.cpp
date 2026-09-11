#include <bits/stdc++.h>
#define N 500050
#define INF 0x3f3f3f3f
typedef long long ll;
using namespace std;
int t, n, m;
ll k;
int dis[N][2];
vector<int> graph[N];
void bfs() {
    for(int i = 1; i <= n; i++)
        dis[i][0] = dis[i][1] = INF;
    dis[1][0] = 0;
    queue< pair<int, int> > q;
    q.push({1, 0});
    while(!q.empty()) {
        auto [u, d] = q.front();
        q.pop();
        int nextd = d ^ 1;
        for(int v : graph[u]) {
            if(dis[v][nextd] == INF) {
                dis[v][nextd] = dis[u][d] + 1;
                q.push({v, nextd});
            }
        }
    }
}
void solve() {
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) graph[i].clear();
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    bfs();
    for(int i = 1; i <= n; i++) {
        ll ans = LLONG_MAX;
        for(int j = 0; j < 2; j++) {
            if(dis[i][j] == INF)    continue;
            ll d = dis[i][j];
            ll target = ((d + k - 1) / k) * k;
            ll diff = target - d;
            if(!(diff & 1)) {
                ans = min(ans, target);
                continue;
            }
            else {
                if(k & 1) {
                    ans = min(ans, target + k);
                    continue;
                }
            }
        }
        cout << (ans == LLONG_MAX ? -1 : ans) << ' ';
    }
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while(t--)  solve();
    return 0;
}
