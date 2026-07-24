#include <bits/stdc++.h>
#define N 10
using namespace std;
int n, x, y, v;
int a[N][N], dp[N][N][N][N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    while(cin >> x >> y >> v && !(x == 0 && y == 0 && v == 0))
        a[x][y] = v;
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            for(int k = 1; k <= n; k++) {
                for(int l = 1; l <= n; l++) {
                    if(i + j == k + l)
                        dp[i][j][k][l] = max(max(dp[i - 1][j][k - 1][l], dp[i - 1][j][k][l - 1]), max(dp[i][j - 1][k - 1][l], dp[i][j - 1][k][l - 1])) + a[i][j] + a[k][l];
                    if(i == k && j == l)    dp[i][j][k][l] -= a[i][j];
                }
            }
        }
    }
    cout << dp[n][n][n][n];
    return 0;
}