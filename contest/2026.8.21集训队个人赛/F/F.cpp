#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    vector<int> p(n + 1);
    for(int i = 1; i <= n; i++) 
        cin >> p[i];
    vector< vector<int> > dp(2, vector<int> (n + 2, -LLONG_MAX));
    for(int i = 0; i <= 1; i++)
        for(int j = 1; j <= n; j++)
            dp[i][j] = -LLONG_MAX;
    dp[1][0] = 0;
    dp[1][1] = -p[1];
    for(int i = 2; i <= n; i++) {
        for(int j = 0; j <= i; j++) {
            if(j == 0)  dp[i % 2][j] = max(dp[(i - 1) % 2][j], dp[(i - 1) % 2][j + 1] + p[i]);
            else    dp[i % 2][j] = max(max(dp[(i - 1) % 2][j - 1] - p[i], dp[(i - 1) % 2][j + 1] + p[i]), dp[(i - 1) % 2][j]);
        }
    }
    int ans = -LLONG_MAX;
    for(int i = 0; i <= n; i++)
        ans = max(ans, dp[n % 2][i]);
    cout << ans;
    return 0;
}