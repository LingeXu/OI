#include <bits/stdc++.h>
#define M 110
using namespace std;
int m, n, ans = 0x3f3f3f3f, cost = 0;
bool HasMagic = true, RecordMagic = true, CanReach = false;
int color[M][M];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
bool vis[M][M];
/*
void dfs(int x, int y) {
    if(x == m && y == m) {
        CanReach = true;
        ans = min(ans, cost);
        return;
    }
    if(color[x][y] == -1 && !HasMagic)
        return;
    int cost_add = 0;
    if(color[x][y] == -1 && HasMagic) {
        color[x][y] = last_color;
        cost_add = 2;
        cost += cost_add;
        HasMagic = false;
        last_color = color[x][y];
    }
    else if(color[x][y] != -1 && color[x][y] == last_color) 
        HasMagic = true;
    else if(color[x][y] != -1 && color[x][y] != last_color) {
        cost_add = 1;
        cost += cost_add;
        HasMagic = true;    
        last_color = color[x][y];
    }
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if(nx >= 1 && nx <= m && ny >= 1 && ny <= m) {
            dfs(nx, ny);
            cost -= cost_add;
        }
    }
}
*/

void dfs(int x, int y) {
    if(vis[x][y])
        return;
    vis[x][y] = true;
    if(x == m && y == m) {
        CanReach = true;
        ans = min(ans, cost);
        return;
    }
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if(nx >= 1 && nx <= m && ny >= 1 && ny <= m) {
            if(color[nx][ny] == -1 && !HasMagic)
                continue;
            if(color[nx][ny] == -1 && HasMagic) {
                /*
                color[nx][ny] = color[x][y];
                cost += 2;
                HasMagic = false;
                dfs(nx, ny);
                color[nx][ny] = -1;
                cost -= 2;
                HasMagic = true;
                */

                for(int j = 0; j <= 1; j++) {
                    color[nx][ny] = j;
                    cost += 2;
                    HasMagic = false;
                    dfs(nx, ny);
                    vis[nx][ny] = false;
                    color[nx][ny] = -1;
                    cost -= 2;
                    HasMagic = true;
                }
            }
            else if(color[nx][ny] != -1 && color[nx][ny] == color[x][y]) {
                RecordMagic = HasMagic;
                HasMagic = true;
                dfs(nx, ny);
                vis[nx][ny] = false;
                HasMagic = RecordMagic;
            }
            else if(color[nx][ny] != -1 && color[nx][ny] != color[x][y]) {
                cost += 1;
                RecordMagic = HasMagic;
                HasMagic = true;  
                dfs(nx, ny);
                vis[nx][ny] = false;
                cost -= 1;
                HasMagic = RecordMagic;
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
    memset(vis, 0, sizeof(vis));
    dfs(1, 1);
    if(!CanReach)
        cout << -1;
    else
        cout << ans;
    return 0;
}