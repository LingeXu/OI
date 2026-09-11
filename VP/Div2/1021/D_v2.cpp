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
    if(pos_x[step] != x || pos_y[step] != y)  return 0;
    if(step == 2 * k + 1 && pos_x[step] == x && pos_y[step] == y)   return 1;
    int delta_x = pos_x[step + 2] - x;
    int delta_y = pos_y[step + 2] - y;
    if(vis[pos_x[step + 2]][pos_y[step + 2]])   return 0;
    int res = 0;
    if(delta_x == -2 && delta_y == 0) {
        if(vis[x - 1][y])   return 0;
        vis[x - 1][y] = true;
        res = dfs(step + 2,pos_x[step + 2], pos_y[step + 2]);
        vis[x - 1][y] = false;
        vis[pos_x[step + 2]][pos_y[step + 2]] = false;
        return res;
    }
    else if(delta_x == 2 && delta_y == 0) {
        if(vis[x + 1][y])   return 0;
        vis[x + 1][y] = true;
        res = dfs(step + 2,pos_x[step + 2], pos_y[step + 2]);
        vis[x + 1][y] = false;
        vis[pos_x[step + 2]][pos_y[step + 2]] = false;
        return res;
    }
    else if(delta_x == 0 && delta_y == -2) {
        if(vis[x][y - 1])   return 0;
        vis[x][y - 1] = true;
        res = dfs(step + 2,pos_x[step + 2], pos_y[step + 2]);
        vis[x][y - 1] = false;
        vis[pos_x[step + 2]][pos_y[step + 2]] = false;
        return res;
    }
    else if(delta_x == 0 && delta_y == 2) {
        if(vis[x][y + 1])   return 0;
        vis[x][y + 1] = true;
        res = dfs(step + 2,pos_x[step + 2], pos_y[step + 2]);
        vis[x][y + 1] = false;
        vis[pos_x[step + 2]][pos_y[step + 2]] = false;
        return res;
    }
    else if(delta_x == -1 && delta_y == -1) {
        if(!vis[x - 1][y]) {
            vis[x - 1][y] = true;
            res = (res + dfs(step + 2,pos_x[step + 2], pos_y[step + 2])) % MOD;
            vis[x - 1][y] = false;
        }
        if(!vis[x][y - 1]) {
            vis[x][y - 1] = true;
            res = (res + dfs(step + 2,pos_x[step + 2], pos_y[step + 2])) % MOD;
            vis[x][y - 1] = false;
        }
        vis[pos_x[step + 2]][pos_y[step + 2]] = false;
        return res;
    }
    else if(delta_x == -1 && delta_y == 1) {
        if(!vis[x - 1][y]) {
            vis[x - 1][y] = true;
            res = (res + dfs(step + 2,pos_x[step + 2], pos_y[step + 2])) % MOD;
            vis[x - 1][y] = false;
        }
        if(!vis[x][y + 1]) {
            vis[x][y + 1] = true;
            res = (res + dfs(step + 2,pos_x[step + 2], pos_y[step + 2])) % MOD;
            vis[x][y + 1] = false;
        }
        vis[pos_x[step + 2]][pos_y[step + 2]] = false;
        return res;
    }
    else if(delta_x == 1 && delta_y == -1) {
        if(!vis[x][y - 1]) {
            vis[x][y - 1] = true;
            res = (res + dfs(step + 2,pos_x[step + 2], pos_y[step + 2])) % MOD;
            vis[x][y - 1] = false;
        }
        if(!vis[x + 1][y]) {
            vis[x + 1][y] = true;
            res = (res + dfs(step + 2,pos_x[step + 2], pos_y[step + 2])) % MOD;
            vis[x + 1][y] = false;
        }
        vis[pos_x[step + 2]][pos_y[step + 2]] = false;
        return res;
    }
    else if(delta_x == 1 && delta_y == 1) {
        if(!vis[x][y + 1]) {
            vis[x][y + 1] = true;
            res = (res + dfs(step + 2,pos_x[step + 2], pos_y[step + 2])) % MOD;
            vis[x][y + 1] = false;
        }
        if(!vis[x + 1][y]) {
            vis[x + 1][y] = true;
            res = (res + dfs(step + 2,pos_x[step + 2], pos_y[step + 2])) % MOD;
            vis[x + 1][y] = false;
        }
        vis[pos_x[step + 2]][pos_y[step + 2]] = false;
        return res;
    }
    else    return 0;
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
    cout << (dfs(1, pos_x[1], pos_y[1]) + MOD) % MOD << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while(t--)  solve();
    return 0;
}