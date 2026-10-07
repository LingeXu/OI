#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;
int t, n, c;
string s;
void solve() {
    cin >> n >> c >> s;
    int ans = 1, cur = 1;
    if(s[0] == '0' || s[n - 1] == '0') {
        cout << -1 << '\n';
        return;
    }
    for(int i = 0; i < n - 1; i++) {
        if(s[i] == '0') {
            ans = ans * i % MOD;
            cur = (cur * (i % c)) % c;
        }
        else {
            ans = ans * 2 % MOD;
            cur = (cur * 2) % c;
        }
        if(cur == 0) {
            cout << -1 << '\n';
            return;
        }
    }

    //cout << "ans = " << ans << '\n';

    cout << ans << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--)  solve();
    return 0;
}