#include<iostream>
#include<queue>
#include<vector>
#include<map>
#include<cstring>
#define N 310
#define M 310
#define MAXS 30
using namespace std;
int n, m, start_x, start_y, end_x, end_y;
char c[N][M];
int level[N][M];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int cnt[MAXS];
int vis[N][M];
//map<char, vector< pair<int, int > > > mp;
struct pos_inf{
    int x, y;
};
vector<pos_inf> slide[MAXS];
map< pair<int, int>, int > mp;
void bfs(){
    queue< pair<int, int> > q;
    q.push({start_x, start_y});
    memset(level, -1, sizeof(level));
    level[start_x][start_y] = 0;
    while(!q.empty()){
        auto a = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            int nextx = a.first + dx[i];
            int nexty = a.second + dy[i];
            if(nextx >= 1 && nextx <= n && nexty >= 1 && nexty <= m && c[nextx][nexty] != '#'){
                if(c[nextx][nexty] == '='){
                    cout << level[a.first][a.second] + 1;
                    return;
                }
                else if(c[nextx][nexty] == '.'){
                    if(level[nextx][nexty] == -1){
                        level[nextx][nexty] = level[a.first][a.second] + 1;
                        q.push({nextx, nexty});
                    }
                }
                else if (c[nextx][nexty] >= 'A' && c[nextx][nexty] <= 'Z') {
                    int pos = c[nextx][nexty] - 'A' + 1;
                    int id_jmp = 1 - mp[{nextx, nexty}];
                    int jmpx = slide[pos][id_jmp].x;
                    int jmpy = slide[pos][id_jmp].y;
                    if(level[jmpx][jmpy] == -1){
                        level[jmpx][jmpy] = level[a.first][a.second] + 1;
                        q.push({jmpx, jmpy});
                    }
                }
            }
        }
    }
}
int main(){
    memset(cnt, 0, sizeof(cnt));
    memset(vis, 0, sizeof(vis));
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> c[i][j];
            if(c[i][j] == '@'){
                start_x = i;
                start_y = j;
            }
            if(c[i][j] == '='){
                end_x = i;
                end_y = j;
            }
            if(c[i][j] >= 'A' && c[i][j] <= 'Z'){
                int pos = c[i][j] - 'A' + 1;
                slide[pos].push_back({i, j});
                mp[{i, j}] = cnt[pos]++;
            }
        }
    }
    bfs();
    return 0;
}