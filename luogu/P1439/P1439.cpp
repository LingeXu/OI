#include <bits/stdc++.h>
#define N 100010
using namespace std;
int n;
int a[N], b[N], dp[2][N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
        cin >> b[i];
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(a[i] == b[j])
                dp[i % 2][j] = dp[(i - 1) % 2][j - 1] + 1;
            else    dp[i % 2][j] = max(dp[(i - 1) % 2][j], dp[i % 2][j - 1]);

            //cout << i << ' ' << j << ' ' << dp[i][j] << '\n';

        }
    }
    cout << dp[n % 2][n];
    return 0;
}