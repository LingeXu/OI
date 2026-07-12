#include <bits/stdc++.h>
#define N 3030
#define INF 0x3f3f3f3f
typedef long long ll;
using namespace std;
int n, m;
int update_cnt[N];
ll dist[N], d[N][N];
bool inq[N], vis[N];
vector< pair<ll, int> > graph[N];
bool spfa() {
    memset(dist, 0x3f, sizeof(dist));
    dist[0] = 0;
    queue<int> q;
    q.push(0);
    inq[0] = true;
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        inq[x] = false;
        for(auto& e : graph[x]) {
            if(dist[e.second] > dist[x] + e.first) {
                dist[e.second] = dist[x] + e.first;
                if(++update_cnt[e.second] > n)
                    return false;
                if(!inq[e.second]) {
                    q.push(e.second);
                    inq[e.second] = true;
                }
            }
        }
    }
    return true;
}
void dijkstra(int s) {
    memset(vis, 0, sizeof(vis));
    priority_queue< pair<ll, int>, vector< pair<ll, int> >, greater< pair<ll, int> > > pq;
    pq.push({0, s});
    for(int i = 1; i <= n; i++)
        d[s][i] = INF;
    d[s][s] = 0;
    while(!pq.empty()) {
        auto node = pq.top();
        pq.pop();
        if(vis[node.second])  continue;
        vis[node.second] = true;
        for(auto e : graph[node.second]) {
            if(d[s][e.second] > d[s][node.second] + e.first) {
                d[s][e.second] = d[s][node.second] + e.first;
                pq.push({d[s][e.second], e.second});
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({w, v});
    }
    for(int i = 1; i <= n; i++) 
        graph[0].push_back({0, i});
    if(!spfa()) {
        cout << -1;
        return 0;
    }
    for(int i = 1; i <= n; i++)
        for(auto& e : graph[i])
            e.first = e.first + dist[i] - dist[e.second];
    for(int i = 1; i <= n; i++)
        dijkstra(i);
    for(int i = 1; i <= n; i++) {
        ll sum = 0;
        for(int j = 1; j <= n; j++) {
            if(i == j)  continue;
            if(d[i][j] == INF)
                sum += 1LL * j * 1e9;
            else    sum += 1LL * j * (d[i][j] + dist[j] - dist[i]);
        }
        cout << sum << '\n';
    }
    return 0;
}