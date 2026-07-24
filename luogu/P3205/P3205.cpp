#include <bits/stdc++.h>
#define N 1010
const int MOD = 19650827;
typedef long long ll;
using namespace std;
int n;
int h[N];
ll dp[N][N][2];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    memset(dp, 0x3f, sizeof(dp));
    for(int i = 1; i <= n; i++) {
        cin >> h[i];
        dp[i][i][0] = 1;
        dp[i][i][1] = 0;
    }
    for(int len = 2; len <= n; len++) {
        for(int l = 1; l + len - 1 <= n; l++) {
            int r = l + len - 1;
            dp[l][r][0] = (dp[l + 1][r][0] * (h[l] < h[l + 1]) + dp[l + 1][r][1] * (h[l] < h[r])) % MOD;
            dp[l][r][1] = (dp[l][r - 1][0] * (h[r] > h[l]) + dp[l][r - 1][1] * (h[r] > h[r - 1])) % MOD;
        }
    }
    cout << (dp[1][n][0] + dp[1][n][1]) % MOD;
    return 0;
}