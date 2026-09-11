#include <bits/stdc++.h>
const int MOD = 998244353;
typedef long long ll;
using namespace std;
int t, n, x;
__int128 sum = 0, op_cnt = 0, full_blocks = 0;
void solve() {
    sum = op_cnt = full_blocks = 0;
    cin >> n >> x;
    vector<ll> a(n);
    priority_queue<int, vector<int>, greater<int> > deficits;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        full_blocks  += (a[i] / x);
        if(a[i] % x == 0)    continue;
        deficits.push(x - a[i] % x);
    }
    if(x == 1) {
        ll ans = (ll)(sum % MOD);
        cout << ans << '\n';
        return;
    }
    if(x == 2) {
        cout << 0 << '\n';
        return;
    }
    while(full_blocks > 0 && !deficits.empty()) {
        int d = deficits.top();
        deficits.pop();
        if(full_blocks >= d - 1) {
            full_blocks -= (d - 1);
            op_cnt += d;
        }
        else {
            op_cnt += full_blocks;
            deficits.push(d - full_blocks);
            full_blocks = 0;
        }
    }
    if(full_blocks > 0 && deficits.empty()) {
        op_cnt += full_blocks;
        op_cnt += full_blocks / (x - 1);
        full_blocks = 0;
    }
    else if(full_blocks == 0 && !deficits.empty()) {
        while(!deficits.empty() && deficits.top() == 1) {
            op_cnt++;
            deficits.pop();
        }
    }
    ll ans = sum % MOD - (op_cnt % MOD) * ((x - 1) % MOD) % MOD;
    ans = (ans >= 0 ? ans : ans + MOD);
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while(t--)    solve();
    return 0;
}