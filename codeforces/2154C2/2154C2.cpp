#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<bool> isprime(200002, true);
vector<int> primes, spf(200002);
vector<int> cnt(200002, 0), factors;
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
int t, n;
void solve() {
    factors.clear();
    for(int i = 0; i <= 200000; i++)
        cnt[i] = 0;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) 
        cin >> a[i];
    int mn1 = LLONG_MAX, mn2 = LLONG_MAX;
    cout << "OK!\n";
    for(int i = 0; i < n; i++) {
        cin >> b[i];
        int cur;
        if(a[i] % 2 == 0)   cur = 0;
        else    cur = b[i];
        if(cur <= mn1) {
            mn2 = mn1;
            mn1 = cur;
            continue;
        }
        if(cur > mn1 && cur <= mn2)   mn2 = b[i];
    }
    int ans = mn1 + mn2;
    if(ans == 0) {
        cout << 0 << '\n';
        return;
    }

    cout << "OK!\n";

    for(int i = 0; i < n; i++) {
        int record = a[i];
        while(a[i] > 1) {
            int p = spf[a[i]];
            if(++cnt[p] == 2) {
                cout << 0 << '\n';
                return;
            }
            factors.push_back(p);
            while(a[i] % p == 0)    a[i] /= p;
        }
        a[i] = record;
    }

    cout << "OK!\n";

    sort(factors.begin(), factors.end());
    factors.erase(unique(factors.begin(), factors.end()), factors.end());
    for(int i = 0; i < n; i++) {
        int cur = a[i] + 1;
        while(cur > 1) {
            int p = spf[cur];
            if(cnt[p] == 1) {
                ans = min(ans, b[i]);
                break;
            }
            while(cur % p == 0)    cur /= p;
        }
    }

    cout << "OK!\n";

    vector<int> mnid;
    for(int i = 0; i < n; i++)
        if(b[i] == mn1)
            mnid.push_back(i);
    if((int)mnid.size() > 1) {
        cout << ans << '\n';
        return;
    }

    cout << "OK!\n";

    int id = mnid[0];
    for(int num : factors)
        if(a[id] % num != 0)
            ans = min(ans, b[id] * (num - a[id] % num));
    cout << ans << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    euler_sieve(200001);
    cin >> t;
    while(t--)  solve();
    return 0;
}