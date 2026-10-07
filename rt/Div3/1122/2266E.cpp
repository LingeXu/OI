#include <bits/stdc++.h>
#define int long long
using namespace std;
#define N 200020
int t, n, k, cur = 0;
vector<int> primes, spf(N + 1), stamp(N + 1), dp(N + 1);
vector<bool> isprime(N + 1, true);
void euler_sieve(int n) {
    for(int i = 2; i <= n; i++) {
        if(isprime[i]) {
            primes.push_back(i);
            spf[i] = i;
        }
        for(int num : primes) {
            if(num * i > n)
                break;
            isprime[num * i] = false;
            spf[num * i] = num;
            if(i % num == 0)    break;
        }
    }
}
int dfs(int u) {
    if(u <= k)
        return dp[u] = 0;
    if(spf[u] == u)
        return dp[u] = 1;
    if(stamp[u] == cur) return dp[u];
    stamp[u] = cur;
    dp[u] = LLONG_MAX;
    for(int i = u; i > 1;) {
        int p = spf[i];
        i /= p;
        dp[u] = min(dp[u], 1 + p * dfs(u / p));
        if(dp[u] == 1)  break;
    }
    return dp[u];
}
void solve() {
    cur++;
    cin >> n >> k;
    unordered_map<int, int> mp;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(x <= k)  continue;
        mp[x]++;
    }
    int ans = 0;
    for(auto &[u, c] : mp)
        ans += c * dfs(u);
    cout << ans << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    euler_sieve(N);
    cin >> t;
    while(t--)  solve();
    return 0;
}