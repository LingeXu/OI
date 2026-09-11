#include <bits/stdc++.h>
#define N 1001
#define M 1001
#define INF 0x3f3f3f3f
using namespace std;
int n, m, q, op, x, y, v, new_x, new_y, last_ans = 0;
int grid[N][M], last[N][M];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
bool record[N][M];
struct inf {
    int x, y, sz;
    bool operator<(const inf& other) const {
        return sz < other.sz;  
    }
};

/*int dfs(int x, int y, int sz, int& cnt) {
    vis[x][y] = sz;
    for(int i = 0; i < 4; i++) {
        int nextx = x + dx[i];
        int nexty = y + dy[i];
        if(nextx < 1 || nextx > n || nexty < 1 || nexty > m || vis[nextx][nexty] == sz || grid[nextx][nexty] > sz)    continue;
        sz++;
        dfs(nextx, nexty, sz, ++cnt);
        sz--;
    }
    return cnt;
}*/

int bfs(int x, int y, int sz) {
    memset(last, 0, sizeof(last));
    memset(record, 0, sizeof(record));
    int res = 0;
    priority_queue<inf, vector<inf>, greater<inf> > q;
    q.push({x, y, sz});
    while(!q.empty()) {
        auto g = q.top();
        q.pop();
        if(g.sz <= last[g.x][g.y])    continue;
        last[g.x][g.y] = g.sz;
        if(!record[g.x][g.y]) {
            res++;
            record[g.x][g.y] = true;
        }
        for(int i = 0; i < 4; i++) {
            int nextx = g.x + dx[i];
            int nexty = g.y + dy[i];
            if(nextx < 1 || nextx > n || nexty < 1 || nexty > m || grid[nextx][nexty] > g.sz)
                continue;
            q.push({nextx, nexty, g.sz + 1});
        }
    }
    return res;
}
bool check(int x, int k) {
    return (bfs(new_x, new_y, grid[new_x][new_y] + x) - 1 == k ? 1 : 0);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(grid, 0x3f, sizeof(grid));
    cin >> n >> m >> q;
    for(int i = 1; i <= q; i++) {
        cin >> op >> x >> y;
        new_x = x ^ last_ans;
        new_y = y ^ last_ans;
        if(op == 1) {
            cin >> v;
            last_ans = bfs(new_x, new_y, v) - 1;
            cout << last_ans << '\n';
            grid[new_x][new_y] = v;
        }
        if(op == 2) {
            int Left = 0;
            int Right = 1e9;
            int ans = -1;
            int k = bfs(new_x, new_y, grid[new_x][new_y] + Right);
            while(Left <= Right) {
                int Mid = Left + (Right - Left) / 2;
                if(check(Mid, k)) {
                    ans = Mid;
                    Right = Mid - 1;
                }
                else    Left = Mid + 1;
            }
            cout << ans << '\n';
            last_ans = ans;
        }
    }
    return 0;
}