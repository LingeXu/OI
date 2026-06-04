#include<iostream>
#include<queue>
#include<cstring>
#define X 310
#define INF 0x3f3f3f3f
using namespace std;
bool ok;
int vis[X][X], level[X][X];
struct pos{
    int x, y;
};
void bfs(int u, int v){
    memset(level, -1, sizeof(level));
    queue<pos> q;
    q.push({0, 0});
    level[0][0] = 0;
    while(!q.empty()){
        pos a = q.front();
        if(vis[a.x][a.y] > 100000){
            ok =true;
            cout << level[a.x][a.y];
            return;
        }
        q.pop();
        if(level[a.x + 1][a.y] == -1 && vis[a.x + 1][a.y] > level[a.x][a.y] + 1){
            q.push({a.x + 1, a.y});
            level[a.x + 1][a.y] = level[a.x][a.y] + 1;
        }
        if(level[a.x][a.y + 1] == -1 && vis[a.x][a.y + 1] > level[a.x][a.y] + 1){
            q.push({a.x, a.y + 1});
            level[a.x][a.y + 1] = level[a.x][a.y] + 1;
        }
        if(a.x - 1 >= 0){
            if(level[a.x - 1][a.y] == -1 && vis[a.x - 1][a.y] > level[a.x][a.y] + 1){
                q.push({a.x - 1, a.y});
                level[a.x - 1][a.y] = level[a.x][a.y] + 1;
            }
        }
        if(a.y - 1 >= 0){
            if(level[a.x][a.y - 1] == -1 && vis[a.x][a.y - 1] > level[a.x][a.y] + 1){
                q.push({a.x, a.y - 1});
                level[a.x][a.y - 1] = level[a.x][a.y] + 1;
            }
        }
    }
}
int main(){
    memset(vis, 0x3f, sizeof(vis));
    int m;
    cin >> m;
    for(int i = 1; i <= m; i++){
        int x, y, t;
        cin >> x >> y >> t;
        vis[x][y] = min(vis[x][y], t);
        vis[x + 1][y] = min(vis[x + 1][y], t);
        vis[x][y + 1] = min(vis[x][y + 1], t);
        if(x - 1 >= 0)  vis[x - 1][y] = min(vis[x - 1][y], t);
        if(y - 1 >= 0)  vis[x][y - 1] = min(vis[x][y - 1], t);
    }
    bfs(0, 0);
    if(!ok)
        cout << -1;
    return 0;
}