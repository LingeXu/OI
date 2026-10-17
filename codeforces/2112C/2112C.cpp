#include <bits/stdc++.h>
using namespace std;
#define int long long
int t, n;
void solve() {
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    int mx = a.back(), ans = 0;
    for(int i = 0; i < n - 2; i++) {
        for(int j = i + 1; j < n - 1; j++) {
            int pos_l = upper_bound(a.begin(), a.end(), a.back() - a[i] - a[j]) - a.begin();
            pos_l = max(pos_l, j + 1);
            int pos_r = lower_bound(a.begin(), a.end(), a[i] + a[j]) - a.begin() - 1;
            if(pos_l <= pos_r)
                ans += pos_r - pos_l + 1;
            //cout << "i = " << i << ", j = " << j << ", ans = " << ans << '\n';
        }
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