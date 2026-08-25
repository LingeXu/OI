#include <bits/stdc++.h>
#define N 303
using namespace std;
int n, s, ans = 0x3f3f3f3f;
int dis[N][N];
void floyd() {
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> s;
    memset(dis, 0x3f, sizeof(dis));
    for(int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dis[u][v] = min(dis[u][v], w);
        dis[v][u] = min(dis[v][u], w);
    }
    for(int i = 1; i <= n; i++)
        dis[i][i] = 0;
    floyd();
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(dis[i][j] <= s) {
                int ecc = 0;
                for(int k = 1; k <= n; k++) 
                    ecc = max(ecc, (dis[k][i] + dis[k][j] - dis[i][j]) / 2);
                ans = min(ans, ecc);
            }
        }
    }
    cout << ans;
    return 0;
}