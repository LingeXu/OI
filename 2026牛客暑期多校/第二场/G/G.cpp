#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> factor(ll n) {
    vector<ll> res;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            res.push_back(i);
            while (n % i == 0) n /= i;
        }
    }
    if(n > 1)    res.push_back(n);
    return res;
}
ll coprimeCount(ll x, const vector<ll>& primes) {
    ll res = 0;
    int k = primes.size();
    for (int mask = 1; mask < (1 << k); mask++) {
        ll mult = 1;
        int bits = 0;
        for (int i = 0; i < k; i++) {
            if ((mask >> i) & 1) {
                mult *= primes[i];
                bits++;
            }
        }
        if (bits & 1) res += x / mult;
        else res -= x / mult;
    }
    return x - res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        ll l, r, n;
        cin >> l >> r >> n;
        vector<ll> primes = factor(n);
        ll ans = 2 * (r - l + 1) - (coprimeCount(r, primes) - coprimeCount(l - 1, primes));
    }
    return 0;
}