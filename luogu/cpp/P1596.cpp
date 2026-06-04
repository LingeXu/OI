#include<iostream>
#define N 110
#define M 110
using namespace std;
int n, m, cnt = 0;
char c[N][M];
bool vis[N][M];
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
void dfs(int x, int y){
    vis[x][y] = true;
    for(int i = 0; i < 8; i++){
        int nextx = x + dx[i];
        int nexty = y + dy[i];
        if(nextx >= 1 && nextx <= n && nexty >= 1 && nexty <= m && c[nextx][nexty] == 'W' && !vis[nextx][nexty])
            dfs(nextx, nexty);
    }
}
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> c[i][j];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(!vis[i][j] && c[i][j] == 'W'){
                cnt++;
                dfs(i, j);
            }
        }
    }
    cout << cnt;
    return 0;
}