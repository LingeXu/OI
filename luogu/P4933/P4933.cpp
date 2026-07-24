#include <bits/stdc++.h>
#define N 1010
#define V 20020
#define MOD 998244353
using namespace std;
int n, ans = 0;
int h[N], dp[N][2 * V];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> h[i];
    for(int i = 1; i <= n; i++) {
        ans = (ans + 1) % MOD;
        for(int j = 1; j < i; j++) {
            int d = h[i] - h[j] + V;
            dp[i][d] = (dp[i][d] + dp[j][d] + 1) % MOD;
            ans = (ans + dp[j][d] + 1) % MOD;
        }
    }
    cout << ans % MOD;
    return 0;
}