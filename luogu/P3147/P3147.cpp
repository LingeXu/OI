#include <bits/stdc++.h>
#define N 262150
using namespace std;
int n, ans = 0;
int a[N];
int dp[60][60];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[a[i]][i] = i + 1;
    }
    for(int i = 2; i <= 58; i++) {
        for(int j = 1; j <= n; j++) {
            if(!dp[i][j])
                dp[i][j] = dp[i - 1][dp[i - 1][j]];
            if(dp[i][j])
                ans = max(ans, i);
        }
    }
    cout << ans;
    return 0;
}