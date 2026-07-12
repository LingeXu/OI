#include <bits/stdc++.h>
#define N 55
#define INF 0x3f3f3f3f
using namespace std;
int n, m, q;
int dis[N][N][N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(dis, 0x3f, sizeof(dis));
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dis[u][v][1] = min(dis[u][v][1], w);
    }
    for(int i = 1; i <= n; i++)
        dis[i][i][0] = 0;
    for(int l = 2; l < n; l++)
        for(int w = 1; w <= n; w++)
            for(int u = 1; u <= n; u++)
                for(int v = 1; v <= n; v++)
                    dis[u][v][l] = min(dis[u][v][l], dis[u][w][l - 1] + dis[w][v][1]);
    cin >> q;
    for(int i = 1; i <= q; i++) {
        int x, y;
        cin >> x >> y;
        double ans = INF;
        bool ok = false;
        for(int length = 1; length < n; length++) {
            if(dis[x][y][length] != INF) {
                ok = true;
                ans = min(ans, (double)dis[x][y][length] / length);
            }
        }
        if(ok)  cout << fixed << setprecision(3) << ans << '\n';
        if(!ok) cout << "OMG!" << '\n';
    }
    return 0;
}