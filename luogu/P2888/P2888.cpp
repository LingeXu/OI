#include <bits/stdc++.h>
#define N 310
using namespace std;
int n, m, t;
int dist[N][N];
vector< pair<int, int> > graph[N];
void floyd() {
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                dist[i][j] = min(dist[i][j], max(dist[i][k], dist[k][j]));
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> t;
    memset(dist, 0x3f, sizeof(dist));
    for(int i = 1; i <= n; i++)
        dist[i][i] = 0;
    for(int i = 1; i <= m; i++) {
        int s, e, h;
        cin >> s >> e >> h;
        dist[s][e] = h;
    }
    floyd();
    for(int i = 1; i <= t; i++) {
        int a, b;
        cin >> a >> b;
        if(dist[a][b] != 0x3f3f3f3f)    cout << dist[a][b] << '\n';
        else    cout << -1 << '\n';
    }
    return 0;
}