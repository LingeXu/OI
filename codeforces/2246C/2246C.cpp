#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;
int t, n;
int quick_pow(int a, int p) {
    int res = 1, base = a;
    while(p) {
        if(p & 1)   res = res * base % MOD;
        base = base * base % MOD;
        p >>= 1;
    }
    return res;
}
void solve() {
    cin >> n;
    vector<int> a(n);
    unordered_map<int, int> mp;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    int base = 1;
    a.erase(unique(a.begin(), a.end()), a.end());
    int cnt = 1;
    for(int i = 0; i < (int)a.size() - 1; i++) 
        if(a[i] + 1 == a[i + 1])
            cnt++;
    for(int i = 0; i < (int)a.size(); i++)
        base = base * quick_pow(2, mp[a[i]] - 1) % MOD;
    if(a[0] != -1) {
        cout << base % MOD << '\n';
        return;
    }
    cout << cnt * (base % MOD) % MOD << '\n';
    return;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while(t--) solve();
    return 0;
}