#include <bits/stdc++.h>
#define N 101
using namespace std;
int n, start_x, start_y, end_x, end_y, ans = 0x3f3f3f3f;
char c[N][N];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int vis[N][N][4];
void dfs(int x, int y, int cnt, int dir) {
    if(cnt >= ans)
        return;
    if(x == end_x && y == end_y) {
        ans = cnt;
        return;
    }
    for(int i = 0; i < 4; i++) {
        int nextx = x + dx[i];
        int nexty = y + dy[i];
        if(nextx >= 1 && nextx <= n && nexty >= 1 && nexty <= n && c[nextx][nexty] != 'x') {
            if(vis[nextx][nexty][i] <= cnt + (i != dir))
                continue;
            vis[nextx][nexty][i] = cnt + (i != dir);
            dfs(nextx, nexty, cnt + (i != dir), i);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> c[i][j];
            if(c[i][j] == 'A') {
                start_x = i;
                start_y = j;
            }
            if(c[i][j] == 'B') {
                end_x = i;
                end_y = j;
            }
        }
    }
    if(start_x == end_x && start_y == end_y) {
        cout << 0;
        return 0;
    }
    memset(vis, 0x3f, sizeof(vis));
    dfs(start_x, start_y, -1, -1);
    cout << (ans == 0x3f3f3f3f ? -1 : ans);
    return 0;
}