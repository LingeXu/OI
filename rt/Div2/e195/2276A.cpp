#include <bits/stdc++.h>
using namespace std;
#define int long long
int t, n, m;
void solve() {
    cin >> n >> m;
    if(n <= m) {
        cout << -1 << '\n';
        return;
    }
    cout << min(n - m, min((n + 1) / 2, m)) << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--)  solve();
    return 0;
}