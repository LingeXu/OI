#include <bits/stdc++.h>
#define N 505
using namespace std;
int n;
int a[N], dp[N][N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    memset(dp, 0x3f, sizeof(dp));
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[i][i] = 1;
    }
    for(int len = 2; len <= n; len++) {
        for(int l = 1; l + len - 1 <= n; l++) {
            int r = l + len - 1;
            if(a[l] == a[r]) {
                if(len == 2)    dp[l][r] = 1;
                else    dp[l][r] = dp[l + 1][r - 1];
            }
            else
                for(int k = l; k < r; k++)
                    dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r]);
        }
    }
    cout << dp[1][n];
    return 0;
}