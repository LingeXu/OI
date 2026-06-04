#include<iostream>
#include<queue>
#include<cstring>
#define N 6
#define M 6
typedef long long ll;
using namespace std;
int n, m, t, sx, sy, fx, fy;
bool IsAvailable[N][M], vis[N][M];
ll method[N][M];
void bfs(int u, int v){
    queue< pair<int, int> > q;
    q.push({u, v});
    vis[u][v] = true;
    while(!q.empty()){
        auto x = q.front();
        q.pop();
        if(x.first - 1 >= sx && IsAvailable[x.first - 1][x.second] && !vis[x.first - 1][x.second]){
            method[x.first - 1][x.second] += method[x.first][x.second];
            vis[x.first - 1][x.second] = true;
            q.push({x.first - 1, x.second});
        }
        if(x.first + 1 <= sx + n - 1 && IsAvailable[x.first + 1][x.second] && !vis[x.first + 1][x.second]){
            method[x.first + 1][x.second] += method[x.first][x.second];
            vis[x.first + 1][x.second] = true;
            q.push({x.first + 1, x.second});
        }
        if(x.second - 1 >= sy && IsAvailable[x.first][x.second - 1] && !vis[x.first][x.second - 1]){
            method[x.first][x.second - 1] += method[x.first][x.second];
            vis[x.first][x.second - 1] = true;
            q.push({x.first, x.second - 1});
        }
        if(x.second + 1 <= sy + m - 1 && IsAvailable[x.first][x.second + 1] && !vis[x.first][x.second + 1]){
            method[x.first][x.second + 1] += method[x.first][x.second];
            vis[x.first][x.second + 1] = true;
            q.push({x.first, x.second + 1});
        }
    }
}
int main(){
    memset(IsAvailable, 1, sizeof(IsAvailable));
    cin >> n >> m >> t >> sx >> sy >> fx >> fy;
    method[sx][sy] = 1;
    for(int i = 1; i <= t; i++){
        int x, y;
        cin >> x >> y;
        IsAvailable[x][y] = false;
    }
    bfs(sx, sy);
    cout << method[fx][fy];
    return 0;
}