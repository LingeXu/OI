#include <bits/stdc++.h>
#define N 1010
#define M 1010
#define K 500050
const int MOD = 1e9 + 7;
using namespace std;
int t, n, m, k;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int pos_x[K], pos_y[K];
bool vis[N][M];
int dfs(int step, int x, int y) {
    vis[x][y] = true;
    if(pos_x[step] != 0 && pos_y[step] != 0 && (pos_x[step] != x || pos_y[step] != y))  return 0;
    if(step == 2 * k + 1 && pos_x[step] == x && pos_y[step] == y)   return 1;
    int nx;
    if(step & 1) {
        nx = step + 2;
        if(abs(x - pos_x[nx]) + abs(y - pos_y[nx]) > 2)
            return 0;
    }
    else {
        nx = step + 1;
        if(abs(x - pos_x[nx]) + abs(y - pos_y[nx]) > 1)
            return 0;
    }
    int res = 0;
    for(int i = 0; i < 4; i++) {
        int nextx = x + dx[i];
        int nexty = y + dy[i];
        if(nextx >=1 && nextx <= n && nexty >= 1 && nexty <= m && !vis[nextx][nexty]) {
            res = (res + dfs(step + 1, nextx, nexty)) % MOD;
            vis[nextx][nexty] = false;
        }
    }
    return res;
}
void solve() {
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= m; j++)
            vis[i][j] = false;
    for(int i = 1; i <= 2 * k + 1; i++)
        pos_x[i] = pos_y[i] = 0;
    for(int i = 1; i <= k + 1; i++) {
        int x, y;
        cin >> x >> y;
        pos_x[2 * i - 1] = x;
        pos_y[2 * i - 1] = y;
    }
    cout << dfs(1, pos_x[1], pos_y[1]) % MOD << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while(t--)  solve();
    return 0;
}