#include <bits/stdc++.h>
using namespace std;
int n, m;
int dist[20005];
vector<int> graph[20005];
int bfs() {
    queue<int> q;
    q.push(n);
    while(!q.empty()) {
        int x = q.front();
        q.pop();
        for(int u : graph[x]) {
            if(dist[u] > dist[x] + 1) {
                dist[u] = dist[x] + 1;
                q.push(u);
                if(u == m)  return dist[u];
            }
        }
    }
}
int main() {
    cin >> n >> m;
    if(n >= m) {
        cout << n - m;
        return 0;
    }
    for(int i = 1; i <= 19998; i++) {
        if(i > 1)
            graph[i].push_back(i - 1);
        if(i < 10000)
            graph[i].push_back(2 * i);
    }
    memset(dist, 0x3f, sizeof(dist));
    dist[n] = 0;
    cout << bfs();
    return 0;
}