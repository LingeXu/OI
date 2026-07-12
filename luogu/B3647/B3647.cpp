#include <bits/stdc++.h>
#define N 110
using namespace std;
int n, m;
int dist[N][N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    memset(dist, 0x3f, sizeof(dist));
    for(int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = min(dist[v][u], w);
    }
    for(int i = 1; i <= n; i++)
        dist[i][i] = 0;
    for(int w = 1; w <= n; w++)
        for(int u = 1; u <= n; u++)
            for(int v = 1; v <= n; v++)
                dist[u][v] = min(dist[u][v], dist[u][w] + dist[w][v]);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << dist[i][j];
            if(j != n)  cout << ' ';
        }
        cout << '\n';
    }
    return 0;
}