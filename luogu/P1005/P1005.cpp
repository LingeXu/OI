#include <bits/stdc++.h>
#define N 85
#define M 85
typedef long long ll;
using namespace std;
int n, m;
__int128 ans = 0;
void out(__int128 x) {
    if(x == 0) {
        cout << 0;
        return;
    }
    string s;
    while(x) {
        s += (x % 10 + '0');
        x /= 10;
    }
    reverse(s.begin(), s.end());
    cout << s;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        __int128 a[M], dp[M][M];
        memset(dp, 0, sizeof(dp));
        for(int j = 1; j <= m; j++) {
            ll x;
            cin >> x;
            a[j] = x;
        }
        for(int len = 1; len <= m; len++) {
            for(int l = 1; l + len - 1 <= m; l++) {
                int r = l + len - 1;
                dp[l][r] = max(dp[l + 1][r] + a[l], dp[l][r - 1] + a[r]) * 2;
            }
        }
        ans += dp[1][m];
    }
    out(ans);
    return 0;
}