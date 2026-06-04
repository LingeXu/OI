#include<iostream>
#define N 6
#define M 6
using namespace std;
int n, m, t, sx, sy, fx, fy, ans = 0;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
bool pos[N][M], vis[N][M];
void dfs(int u, int v){
    if(u == fx && v == fy)  ans++;
    vis[u][v] = true;
    for(int i = 0; i < 4; i++){
        int new_x = u + dx[i], new_y = v + dy[i];
        if(new_x >= 1 && new_x <= n && new_y >=1 && new_y <= m && !vis[new_x][new_y] && pos[new_x][new_y] == 0){
            dfs(new_x, new_y);
            vis[new_x][new_y] = false;
        }
    }
}
int main(){
    cin >> n >> m >> t >> sx >> sy >> fx >> fy;
    for(int i = 0; i < t; i++){
        int x, y;
        cin >> x >> y;
        pos[x][y] = 1;
    }
    dfs(sx, sy);
    cout << ans;
    return 0; 
}