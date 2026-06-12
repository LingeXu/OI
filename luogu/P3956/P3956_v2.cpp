#include <bits/stdc++.h>
#define M 110
using namespace std;
int m, n, ans = 0x3f3f3f3f;
int color[M][M];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int dp[M][M][2][2];
bool vis[M][M];
void dfs(int x, int y, int cost, bool hasMagic, int lastColor) {
    if(cost >= ans) return;
    if(dp[x][y][hasMagic][lastColor] <= cost) return;
    if(vis[x][y]) return;
    vis[x][y] = true;
    dp[x][y][hasMagic][lastColor] = cost;
    if(x == m && y == m) {
        ans = min(ans, cost);
        return;
    }
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if(nx < 1 || nx > m || ny < 1 || ny > m) continue;
        if(color[nx][ny] != -1) {
            if(color[nx][ny] == lastColor) {
                dfs(nx, ny, cost, true, color[nx][ny]);
                vis[nx][ny] = false;
            }
            else {
                dfs(nx, ny, cost + 1, true, color[nx][ny]);
                vis[nx][ny] = false;
            }
        }
        else if(color[nx][ny] == -1 && hasMagic) {
            for(int j = 0; j <= 1; j++) {
                dfs(nx, ny, cost + 2 + (j != lastColor), false, j);
                vis[nx][ny] = false;
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> n;
    memset(color, -1, sizeof(color));
    for(int i = 1; i <= n; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        color[x][y] = c;
    }
    memset(dp, 0x3f, sizeof(dp));
    memset(vis, false, sizeof(vis));
    dfs(1, 1, 0, true, color[1][1]);
    if(ans == 0x3f3f3f3f)
        cout << -1 << endl;
    else
        cout << ans << endl;
    return 0;
}