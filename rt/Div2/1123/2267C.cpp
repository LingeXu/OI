#include <bits/stdc++.h>
using namespace std;
#define int long long
int t, n, x;
void solve() {
    cin >> n >> x;
    vector<int> a(n);
    unordered_map<int, int> mp;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    if(x == 1) {
        cout << 0 << '\n';
        return;
    }
    vector<int> divisor;
    for(int i = 1; i * i <= x; i++) {
        if(x % i == 0) {
            if(i != 1)
                divisor.push_back(i);
            if(i != x / i)
                divisor.push_back(x / i);
        }
    }
    int ans = 0;
    for(int g : divisor) {
        int cur = 0;
        for(auto &[val, cnt] : mp) {
            if(val % g != 0)   continue;
            cur += val * cnt;
        }
        ans = max(ans, cur);
    }
    cout << ans << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--)  solve();
    return 0;
}