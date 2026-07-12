#include <bits/stdc++.h>
#define N 55
#define K 31
using namespace std;
int n, m;
int dis[N][N];
bool has_edge[N][N][K];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    memset(dis, 0x3f, sizeof(dis));
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        has_edge[u][v][0] = true;
        dis[u][v] = 1;
    }
    for(int i = 1; i < K; i++) {
        for(int w = 1; w <= n; w++) {
            for(int u = 1; u <= n; u++) {
                for(int v = 1; v <= n; v++) {
                    if(has_edge[u][w][i - 1] && has_edge[w][v][i - 1]) {
                        has_edge[u][v][i] = true;
                        dis[u][v] = 1; 
                    }
                }
            }
        }
    }
    for(int w = 1; w <= n; w++) 
        for(int u = 1; u <= n; u++) 
            for(int v = 1; v <= n; v++) 
                dis[u][v] = min(dis[u][v], dis[u][w] + dis[w][v]);
    cout << dis[1][n];
    return 0;
}