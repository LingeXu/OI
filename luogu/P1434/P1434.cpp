#include<iostream>
#include<algorithm>
#include<cstring>
#define R 110
#define C 110
using namespace std;
int r, c;
int height[R][C], dist_begin[R][C];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int dfs(int x, int y){
    if(dist_begin[x][y])    return dist_begin[x][y];
    dist_begin[x][y] = 1;
    for(int i = 0; i < 4; i++){
        int nextx = x + dx[i];
        int nexty = y + dy[i];
        if(nextx >= 1 && nextx <= r && nexty >= 1 && nexty <= c && height[nextx][nexty] < height[x][y])
            dist_begin[x][y] = max(dist_begin[x][y], dfs(nextx, nexty) + 1);
    }
    return dist_begin[x][y];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> r >> c;
    for(int i = 1; i <= r; i++)
        for(int j = 1; j <= c; j++)
            cin >> height[i][j];
    memset(dist_begin, 0, sizeof(dist_begin));
    int max_length = 0;
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            if(!dist_begin[i][j]){
                int route_length = dfs(i, j);
                max_length = max(max_length, route_length);
            }
        }
    }
    cout << max_length;
    return 0;
}