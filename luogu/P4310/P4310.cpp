#include <bits/stdc++.h>
#define N 100010
using namespace std;
int n, ans = 0;
int a[N], dp[32];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        int k = 1;
        for(int j = 0; j <= 31; j++)
            if((a[i] & (1 << j)) != 0)
                k = max(k, dp[j] + 1);
        for(int j = 0; j <= 31; j++)
            if((a[i] & (1 << j)) != 0)
                dp[j] = k;
        ans = max(ans, k);
    }
    cout << ans;
    return 0;
}