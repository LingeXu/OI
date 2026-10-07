#include <bits/stdc++.h>
using namespace std;
#define int long long
int t, n;
void solve() {
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        cin >> b[i];
    if(n == 1) {
        cout << max(-a[0], b[0]) << '\n';
        return;
    }
    int pre_mx = max(-a[0], b[0]), pre_mn = min(-a[0], b[0]);
    int mx, mn;
    for(int i = 1; i < n; i++) {
        mx = max(pre_mx - a[i], b[i] - pre_mn);
        mn = min(pre_mn - a[i], b[i] - pre_mx);
        pre_mx = mx;
        pre_mn = mn;
    }
    cout << pre_mx << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--)  solve();
    return 0;
}