#include <bits/stdc++.h>
#define X 505
#define Y 505
using namespace std;
int x, y, ans = 0;
char c[X][Y];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
bool vis[X][Y], res[X][Y];
void dfs(int u, int v) {
    if(vis[u][v])
        return;
    vis[u][v] = res[u][v] = true;
    for(int i = 0; i < 4; i++) {
        int nextu = u + dx[i];
        int nextv = v + dy[i];
        if(nextu >= 1 && nextu <= x && nextv >= 1 && nextv <= y && c[nextu][nextv] == '0') 
            dfs(nextu, nextv);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> x >> y;
    for(int i = 1; i <= x; i++) 
        for(int j = 1; j <= y; j++) 
            cin >> c[i][j];
    for(int i = 1; i <= x; i++)
        for(int j = 1; j <= y; j++)
            if(c[i][j] == '0' && (i == 1 || i == x || j == 1 || j == y))
                dfs(i, j);
    for(int i = 1; i <= x; i++)
        for(int j = 1; j <= y; j++)
            if(c[i][j] == '0' && !res[i][j]) {
                //cout << i << " " << j << endl;
                ans++;
            }
    cout << ans;
    return 0;
}