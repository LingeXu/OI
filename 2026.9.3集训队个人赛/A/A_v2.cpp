#include <bits/stdc++.h>
#define int long long 
#define MOD 998244353
#define N 200020
using namespace std;
int n, k;
int success[N], fail[N], dp[N], prep[N], g[N], pre_g[N];
int quick_pow(int a, int p) {
    int res = 1;
    while(p) {
        if(p & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        p >>= 1;
    }
    return res;
}
int inv(int x) {
    return quick_pow(x, MOD - 2);
}
int Fail(int l, int r) {
    if(r - l + 1 < k)  return 1;
    dp[l - 1] = 1;
    prep[l - 1] = 1;
    g[l - 1] = 1;
    pre_g[l - 1] = 1;
    for(int i = l; i <= r; i++) {
        prep[i] = prep[i - 1] * success[i] % MOD;
        dp[i] = dp[i - 1] * fail[i] % MOD;
        int win = pre_g[i - 1];
        if(i - k + 1 >= l) 
            win = (win - pre_g[i - k] + MOD) % MOD;
        dp[i] = (dp[i] + win * prep[i]) % MOD;
        g[i] = dp[i - 1] * fail[i] % MOD * inv(prep[i]) % MOD;
        pre_g[i] = (pre_g[i - 1] + g[i]) % MOD;
    }
    return dp[r];
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    vector<int> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        success[i] = a[i] * inv(b[i]) % MOD;
        fail[i] = (1 - success[i] + MOD) % MOD;
    }
    int Pfail = 1;
    for(int i = 1; i <= n; ) {
        if(a[i] == 0) {
            i++;
            continue;
        }
        int l = i, r = i;
        while(r < n && a[r + 1] != 0)    r++;
        Pfail = Pfail * Fail(l, r) % MOD;
        i = r + 1;
    }
    cout << (1 - Pfail + MOD) % MOD;
    return 0;
}