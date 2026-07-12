#include <bits/stdc++.h>
using namespace std;
#define N 51
#define M 51
int n, m, start_x, start_y, end_x, end_y, ans = 0x3f3f3f3f, dir;
char direction;
bool CannotReach[N][M], available[N][M];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1,0, -1, 0};
int record[N][M][4];
void dfs(int x, int y, int step, int dir) {
    if(record[x][y][dir] != -1 && record[x][y][dir] <= step)    return;
    record[x][y][dir] = step;
    if(x == end_x  && y == end_y) {
        ans = min(ans, step);
        return;
    }
    for(int i = 1; i <= 3; i++) {
        int nextx = x + i * dx[dir];
        int nexty = y + i * dy[dir];
        if(nextx >= 1 && nextx < n && nexty >= 1 && nexty < m) {
            if(!available[nextx][nexty])
                break;
            dfs(nextx, nexty, step + 1, dir);
        }
    }
    dfs(x, y, step + 1, (dir + 3) % 4);
    dfs(x, y, step + 1, (dir + 1) % 4);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    memset(available, true, sizeof(available));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> CannotReach[i][j];
            if(CannotReach[i][j]) {
                if(i > 1 && j > 1)
                    available[i - 1][j - 1] = 0;
                if(j > 1)
                    available[i][j - 1] = 0;
                if(i > 1)
                    available[i - 1][j] = 0;
                available[i][j] = 0;
            }
        }
    }

    /*cout << '\n';
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++)
            cout << available[i][j] << ' ';
        cout << '\n';
    }*/

    cin >> start_x >> start_y >> end_x >> end_y >> direction;
    if(direction == 'N')  dir = 3;
    else if(direction == 'E')  dir = 0;
    else if(direction == 'S')  dir = 1;
    else if(direction == 'W')  dir = 2;
    memset(record, -1, sizeof(record));
    dfs(start_x, start_y, 0, dir);
    if(ans == 0x3f3f3f3f)
        ans = -1;
    cout << ans << endl;
    return 0;
}