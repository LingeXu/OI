#include <bits/stdc++.h>
#define R 110
#define C 110
using namespace std;
int r, c;
int h[R][C];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int dp[R][C];
bool vis[R][C];
int dfs(int x, int y) {
    if(vis[x][y])   return dp[x][y];
    vis[x][y] = true;
    for(int i = 0; i < 4; i++){
        int nextx = x + dx[i];
        int nexty = y + dy[i];
        if(nextx >= 1 && nextx <= r && nexty >= 1 && nexty <= c && h[nextx][nexty] < h[x][y])
            dp[x][y] = max(dp[x][y], dfs(nextx, nexty) + 1);
    }
    return dp[x][y];
}
int main() {
    cin >> r >> c;
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            cin >> h[i][j];
            dp[i][j] = 1;
        }
    }
    memset(vis, 0, sizeof(vis));
    int ans = 1;
    for(int i = 1; i <= r; i++)
        for(int j = 1; j <= c; j++)
            if(!vis[i][j])
                ans = max(ans, dfs(i, j));
    cout << ans;
    return 0;
}