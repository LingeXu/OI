#include <bits/stdc++.h>
using namespace std;
#define int long long
int t, n;
int cnt[200002];
vector<bool> isprime(200002, true);
vector<int> primes, spf(200002);
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
void solve() {
    cin >> n;
    vector<int> a(n), b(n), c;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] == 1)   continue;
        c.push_back(a[i]);
    }
    for(int i = 0; i < n; i++) 
        cin >> b[i]; 
    int m = (int)c.size();
    if(m == 0) {
        cout << 2 << '\n';
        return;
    }
    if(m == 1 && c[0] % 2 == 0) {
        cout << 1 << '\n';
        return;
    }
    if(m == 1 && c[0] % 2 != 0) {
        cout << 2 << '\n';
        return;
    }
    memset(cnt, 0, sizeof(cnt));
    for(int i = 0; i < m; i++) {
        int record = c[i];
        while(c[i] > 1) {
            int p = spf[c[i]];
            if(++cnt[p] == 2) {
                cout << 0 << '\n';
                return;
            }
            while(c[i] % p == 0)    c[i] /= p;
        }
        c[i] = record;
    }
    for(int i = 0; i < m; i++) {
        c[i]++;
        while(c[i] > 1) {
            int p = spf[c[i]];
            if(cnt[p] == 1) {
                cout << 1 << '\n';
                return;
            }
            while(c[i] % p == 0)    c[i] /= p;
        }
    }
    cout << 2 << '\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    euler_sieve(200001);
    cin >> t;
    while(t--)  solve();
    return 0;
}