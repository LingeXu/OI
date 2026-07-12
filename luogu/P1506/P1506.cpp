#include <bits/stdc++.h>
#define X 505
#define Y 505
using namespace std;
int x, y, ans = 0;
char c[X][Y];
int res[X][Y];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
bool dfs(int u, int v) {
    if(res[u][v] != -1)
        return res[u][v];
    if(u == 1 || u == x || v == 1 || v == y) {
        res[u][v] = 0;
        return false;
    }
    res[u][v] = 1;
    for(int i = 0; i < 4; i++) {
        int nextu = u + dx[i];
        int nextv = v + dy[i];
        if(nextu >= 1 && nextu <= x && nextv >= 1 && nextv <= y && c[nextu][nextv] != '*') {
            if(!dfs(nextu, nextv)) {
                res[u][v] = 0;
                return false;
            }
        }
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> x >> y;
    for(int i = 1; i <= x; i++)
        for(int j = 1; j <= y; j++)
            cin >> c[i][j];
    memset(res, -1, sizeof(res));
    for(int i = 1; i <= x; i++)
        for(int j = 1; j <= y; j++)
            if(c[i][j] == '0')
                ans += dfs(i, j);
    cout << ans;
    return 0;
}