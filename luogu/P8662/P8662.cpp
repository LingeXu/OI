#include <bits/stdc++.h>
#define N 1010
using namespace std;
int n, ans = 0;
char c[N][N], d[N][N];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
bool vis[N][N];
vector< pair<int, int> > land;
vector< pair<int, int> > dland;
void dfs(int x, int y) {
    vis[x][y] = true;
    for(int i = 0; i < 4; i++) {
        int nextx = x + dx[i];
        int nexty = y + dy[i];
        if(nextx >= 1 && nextx <= n && nexty >= 1 && nexty <= n && c[nextx][nexty] == '#') 
            if(!vis[nextx][nexty])
                dfs(nextx, nexty);
        
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> c[i][j];
            d[i][j] = c[i][j];
            if(c[i][j] == '#')
                land.push_back({i, j});
        }
    }
    for(auto node : land) {
        if(!vis[node.first][node.second]) {
            dfs(node.first, node.second);
            ans++;
        }
    }
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(c[i][j] == '#') {
                bool change = false;
                for(int k = 0; k < 4; k++) {
                    int nextx = i + dx[k];
                    int nexty = j + dy[k];
                    if(nextx >= 1 && nextx <= n && nexty >= 1 && nexty <= n && c[nextx][nexty] == '.') {
                        change = true;
                        break;
                    }
                }
                if(change)
                    d[i][j] = '.';
                else
                    dland.push_back({i, j});
            }
        }
    }
    for(auto node : dland) {
        if(!vis[node.first][node.second]) {
            dfs(node.first, node.second);
            ans--;
        }
    }
    cout << ans;
    return 0;
}