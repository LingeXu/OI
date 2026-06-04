#include<iostream>
#define N 35
using namespace std;
int n;
char c[N][N], ans[N][N];
int CanReachMargin[N][N];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
bool vis[N][N];
bool IsMargin(int x, int y){
    return x == 1 || x == n || y == 1 || y == n;
}
int dfs(int x, int y){
    vis[x][y] = true;
    if(IsMargin(x, y))  return CanReachMargin[x][y] = 1;
    for(int i = 0; i < 4; i++){
        int nextx = x + dx[i];
        int nexty = y + dy[i];
        if(nextx >= 1 && nextx <= n && nexty >= 1 && nexty <= n && !vis[nextx][nexty] && c[nextx][nexty] == '0'){
            if(CanReachMargin[nextx][nexty] == -1) {
                if(dfs(nextx, nexty) == 1)  
                    return CanReachMargin[x][y] = 1;
            }
            else return CanReachMargin[x][y] = CanReachMargin[nextx][nexty];
        }
    }
    return CanReachMargin[x][y] = 0;
}
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> c[i][j];
            ans[i][j] = c[i][j];
        }
    }
    memset(CanReachMargin, -1, sizeof(CanReachMargin));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(c[i][j] == '0'){
                if(CanReachMargin[i][j] == -1){
                    memset(vis, 0, sizeof(vis));
                    if(dfs(i, j) == 0)  ans[i][j] = '2';
                }
                else ans[i][j] = (CanReachMargin[i][j] == 0 ? '2' : '0');
            }
        }
    }
    cout << '\n';
    cout << '\n';
    cout << '\n';
    cout << '\n';
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)
            cout << ans[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}