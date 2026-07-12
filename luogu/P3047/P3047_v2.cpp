#include <bits/stdc++.h>
#define N 100010
using namespace std;
int n, k;
int c[N];
vector<int> graph[N];
int bfs(int start) {
    int sum = 0;
    bool vis[N];
    queue< pair<int, int> > q;
    q.push({0, start});
    vis[start] = true;
    while(!q.empty()) {
        auto x = q.front();
        q.pop();
        sum += c[x.second];
        for(int to : graph[x.second]) {
            if(!vis[to] && x.first + 1 <= k) {
                vis[to] = true;
                q.push({x.first + 1, to});
            }
        }
    }
    return sum;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i = 1; i <= n; i++)
        cin >> c[i];
    for(int i = 1; i <= n; i++)
        cout << bfs(i) << '\n';
    return 0;
}