#include <bits/stdc++.h>
#define N 110
#define INF 0x3f3f3f3f3f3f3f3f
typedef long long ll;
using namespace std;
int n, m;
ll ans = -INF;
int a[N][N];
ll dp[N][N][N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= i; j++)
            cin >> a[i][j];
    for(int i = 1; i <= n + 1; i++)
        for(int j = 1; j <= n + 1; j++)
            for(int k = 0; k <= min(n, m); k++)
                dp[i][j][k] = -INF;
    for(int i = 1; i <= n + 1; i++)
        dp[n + 1][i][0] = 0;
    for(int i = n; i >= 1; i--) {
        for(int j = 1; j <= i; j++) {
            for(int k = 0; k <= min(n, m); k++) {
                if(k == 0)  dp[i][j][0] = max(dp[i + 1][j][0], dp[i + 1][j + 1][0]) + 1LL * a[i][j];
                else    dp[i][j][k] = max(max(dp[i + 1][j][k], dp[i + 1][j + 1][k]) + a[i][j], max(dp[i + 1][j][k - 1], dp[i + 1][j + 1][k - 1]) + 3LL * a[i][j]);
            }
        }
    }
    for(int i = 0; i <= min(n, m); i++)
        ans = max(ans, dp[1][1][i]);
    cout << ans;
    return 0;
}