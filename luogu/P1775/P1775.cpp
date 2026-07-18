#include <bits/stdc++.h>
#define N 303
using namespace std;
int n;
int a[N], s[N], dp[N][N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    memset(s, 0, sizeof(s));
    memset(dp, 0x3f, sizeof(dp));
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
        dp[i][i] = 0;
    }
    for(int len = 2; len <= n; len++) {
        for(int l = 1; l + len - 1 <= n; l++) {
            int r = l + len - 1;
            for(int k = l; k < r; k++) 
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r] + s[r] - s[l - 1]);
        }
    }
    cout << dp[1][n];
    return 0;
}