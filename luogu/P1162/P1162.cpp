#include<iostream>
#define N 35
using namespace std;
int n;
char c[N][N], ans[N][N];
bool vis[N][N];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
bool IsMargin(int x, int y){
    return x == 1 || x == n || y == 1 || y == n;
}
bool dfs(int x, int y){
    vis[x][y] = true;
    if(IsMargin(x, y))  return 1;
    bool ok = false;
    for(int i = 0; i < 4; i++){
        if(ok)  return 1;
        int nextx = x + dx[i];
        int nexty = y + dy[i];
        if(nextx >= 1 && nextx <= n && nexty >= 1 && nexty <= n && c[nextx][nexty] == '0' && !vis[nextx][nexty])
            ok = dfs(nextx, nexty);
    }
    return ok;
}
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> c[i][j];
            ans[i][j] = c[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(ans[i][j] == '0'){
                memset(vis, 0, sizeof(vis));
                ans[i][j] = (dfs(i, j) == 1 ? '0' : '2');
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)
            cout << ans[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}