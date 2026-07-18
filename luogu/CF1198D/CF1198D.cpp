#include <bits/stdc++.h>
#define N 55
using namespace std;
int n;
int f[N][N][N][N];
char c[N][N];
int dfs(int x1, int y1, int x2, int y2) {
    if(f[x1][y1][x2][y2] != -1)
        return f[x1][y1][x2][y2];
    if(x1 == x2 && y1 == y2)
        return f[x1][y1][x2][y2] = (c[x1][y1] == '#');
    int ans = max(x2 - x1 + 1, y2 - y1 + 1);
    for(int i = x1; i < x2; i++)
        ans = min(ans, dfs(x1, y1, i, y2) + dfs(i + 1, y1, x2, y2));
    for(int j = y1; j < y2; j++)
        ans = min(ans, dfs(x1, y1, x2, j) + dfs(x1, j + 1, x2, y2));
    return f[x1][y1][x2][y2] = ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> c[i][j];
    memset(f, -1, sizeof(f));
    cout << dfs(0, 0, n - 1, n - 1);
    return 0;
}