#include<bits/stdc++.h>
#define N 1010
#define W 10010
const int MOD = 1e9 + 7;
using namespace std;
int n, w;
int val[N];
int dp[N][W];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> w;
    for(int i = 1; i <= n; i++)
        cin >> val[i];
    for(int i = 0; i <= w; i += val[1])
        dp[1][i] = 1;
    for(int i = 2; i <= n; i++) {
        for(int j = 0; j <= w; j++) {
            if(j - val[i] >= 0)
                dp[i][j] = (dp[i - 1][j] + dp[i][j - val[i]]) % MOD;
            else    dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[n][w];
    return 0;
}