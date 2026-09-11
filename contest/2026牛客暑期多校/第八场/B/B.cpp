#include <bits/stdc++.h>
const int MOD = 998244353;
typedef long long ll;
using namespace std;
int t, n, m;
void solve() {
    cin >> n >> m;
    vector<bool> forced(2 * n + 1, false);
    bool impossible = false;
    for(int i = 0; i < m; i++) {
        int a;
        cin >> a;
        if(a >= 2 * n)    impossible = true;    
        else    forced[a] = true;
    }
    if(impossible) {
        cout << 0 << '\n';
        return;
    }
    vector< vector<ll> > dp(2, vector<ll>(n + 1, 0));
    dp[0][0] = 1LL;
    for(int i = 1; i <= 2 * n; i++) {
        fill(dp[i & 1].begin(), dp[i & 1].end(), 0);
        for(int j = i & 1; j <= min(i, 2 * n - i); j += 2) {
            if(forced[i]) {
                if(j > 0)
                    dp[i & 1][j] = dp[(i - 1) & 1][j - 1];
            }
            else {
                if(j + 1 <= min(i - 1, 2 * n - i + 1))    dp[i & 1][j] = dp[(i - 1) & 1][j + 1];
                if(j - 1 >= 0 && j - 1 <= min(i - 1, 2 * n - i + 1))    dp[i & 1][j] = (dp[i & 1][j] + dp[(i - 1) & 1][j - 1]) % MOD;
            }
        }
    }
    cout << dp[0][0] << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--)    solve();
    return 0;
}