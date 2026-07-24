#include <bits/stdc++.h>
#define M 55
#define N 55
#define INF 0x3f3f3f3f
using namespace std;
int m, n;
int a[M][N], dp[M][N][M][N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> n;
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            for(int x = 1; x <= m; x++) {
                for(int y = 1; y <= n; y++) {
                    if(i + j != x + y)  continue;
                    dp[i][j][x][y] = max(max(dp[i - 1][j][x - 1][y], dp[i - 1][j][x][y - 1]), max(dp[i][j - 1][x - 1][y], dp[i][j - 1][x][y - 1])) + a[i][j] + a[x][y];
                    if(i == x && j == y && !(i == 1 && j == 1) && !(i == m && j == n))    dp[i][j][x][y] = -INF;
                }
            }
        }
    }
    cout << dp[m][n][m][n];
    return 0;
}