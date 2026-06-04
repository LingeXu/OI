#include <bits/stdc++.h>
#define N 1000010
const int MOD = 1e9 + 7;
typedef long long ll;
using namespace std;
int dp0[N], dp1[N], dp2[N];
int n, d;
ll ans = 0;
int main() {
    cin >> n >> d;
    dp0[0] = 1;
    for(int i = 1; i <= n; i++) {
        dp0[i] = (dp0[i - 1] + dp1[i - 1] + dp2[i - 1]) % MOD;
        int pos = max(0, i - d + 1);
        dp1[i] = (dp0[pos] + dp2[pos]) % MOD;
        dp2[i] = (dp0[pos] + dp1[pos]) % MOD;
    }
    ans = (dp0[n] + dp1[n] + dp2[n]) % MOD;
    cout << ans;
    return 0;
}