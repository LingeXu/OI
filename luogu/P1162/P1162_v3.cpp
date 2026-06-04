#include<iostream>
#include<cstring>
#include<queue>
#define N 35
using namespace std;
int n;
char c[N][N];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
bool vis[N][N];
bool IsMargin(int x, int y){
    return x == 1 || x == n || y == 1 || y == n;
}
void bfs(int x, int y){
    vis[x][y] = true;
    queue< pair<int, int> > q;
    q.push({x, y});
    while(!q.empty()){
        auto a = q.front();
        c[a.first][a.second] = '0';
        q.pop();
        for(int i = 0; i < 4; i++){
            int nextx = a.first + dx[i];
            int nexty = a.second + dy[i];
            if(nextx >= 1 && nextx <= n && nexty >= 1 && nexty <= n && !vis[nextx][nexty] && c[nextx][nexty] == '2'){
                vis[nextx][nexty] = true;
                q.push({nextx, nexty});
            }
        }
    }
}
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> c[i][j];
            c[i][j] = (c[i][j] == '0' ? '2' : '1');
        }
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(c[i][j] == '2' && IsMargin(i, j))
                bfs(i, j);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)
            cout << c[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}