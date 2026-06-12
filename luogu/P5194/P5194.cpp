#include <bits/stdc++.h>
#include <climits>
#define N 1010
#define C INT_MAX
using namespace std;
int n, c;
int weight[N];
int dp[N][C];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> c;
    int w, cnt = 0, ans = 0;
    for(int i = 1; i <= n; i++) {
        cin >> w;
        if(w == c)  ans = c;
        else if(w < c)    weight[++cnt] = w;
        else continue;
    }
    if(ans == c) {
        cout << c;
        return 0;
    }
    for(int i = 1; i <= cnt; i++) {
        for(int j = 0; j <= c; j++) {
            if(j >= weight[i])
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + weight[i]);
            else
                dp[i][j] = dp[i - 1][j];
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans;
    return 0;
}