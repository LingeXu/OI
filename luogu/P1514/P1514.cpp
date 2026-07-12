#include <bits/stdc++.h>
#define N 505
#define M 505
using namespace std;
int n, m, cnt = 0;
int h[N][M], Left[N][M], Right[N][M];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
bool flag[M], vis[N][M];
struct span {
    int l, r;
}s[M];
bool cmp(span a, span b) {
    return a.l < b.l || (a.l == b.l && a.r > b.r);
}
void dfs(int x, int y, int start_y) {
    if(vis[x][y]) {
        s[start_y].l = min(s[start_y].l, Left[x][y]);
        s[start_y].r = max(s[start_y].r, Right[x][y]);
        return;
    }
    vis[x][y] = true;
    if(x == n) {
        flag[y] = true;
        Left[x][y] = y;
        Right[x][y] = y;
    }
    else {
        Left[x][y] = m + 1;
        Right[x][y] = -1;
    }
    for(int i = 0; i < 4; i++) {
        int nextx = x + dx[i];
        int nexty = y + dy[i];
        if(nextx < 1 || nextx > n || nexty < 1 || nexty > m || h[nextx][nexty] >= h[x][y])    continue;
        dfs(nextx, nexty, start_y);
        Left[x][y] = min(Left[x][y], Left[nextx][nexty]);
        Right[x][y] = max(Right[x][y], Right[nextx][nexty]);
    }
    s[start_y].l = min(s[start_y].l, Left[x][y]);
    s[start_y].r = max(s[start_y].r, Right[x][y]);
}
int GetAns() {
    sort(s + 1, s + m + 1, cmp);
    int ans = 0, last = 0, now = 0, idx = 1;
    while(idx <= m && s[idx].l < m) {
        while(s[idx].l <= last + 1) {
            now = max(now, s[idx].r);
            idx++;
        }
        last = now;
        ans++;
        if(last == m)
            return ans;
        idx--;
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= m; j++) 
            cin >> h[i][j];
    for(int i = 1; i <= m; i++) 
        s[i].l = m + 1, s[i].r = -1;
    for(int i = 1; i <= m; i++) 
        dfs(1, i, i);
    for(int i = 1; i <= m; i++)
        if(!flag[i])
            cnt++;
    if(cnt == 0) {
        cout << 1 << '\n';
        /*for(int i = 1; i <= m; i++)
            cout << s[i].l << ' ' << s[i].r << '\n';*/
        cout << GetAns() << '\n';
        return 0;
    }
    else {
        cout << 0 << '\n';
        cout << cnt;
        return 0;
    }
    return 0;
}