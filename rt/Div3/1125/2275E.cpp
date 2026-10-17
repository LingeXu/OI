#include <bits/stdc++.h>
using namespace std;
#define int long long
int t, n;
void solve() {
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
        cin >> b[i];   
    if(n == 1) {
        cout << (a[1] == b[1] ? 2 : 1) << '\n';
        return;
    }
    vector<int> pref_sum(n + 1), suff_sum(n + 1);
    pref_sum[1] = (a[1] == b[1] ? 2 : 1);
    for(int i = 2; i <= n; i++) 
        pref_sum[i] = pref_sum[i - 1] + (a[i] == b[i - 1] ? 2 : 1) + (a[i] == b[i] ? 2 : 1);
    suff_sum[n] = (a[n] == b[n] ? 2 : 1);
    for(int i = n - 1; i >= 1; i--) 
        suff_sum[i] = suff_sum[i + 1] + (a[i] == b[i + 1] ? 2 : 1) + (b[i] == a[i + 1] ? 2 : 1);
    int ans = max(suff_sum[1], pref_sum[n]);
    for(int i = 1; i < n; i++)
        ans = max(ans, pref_sum[i] + suff_sum[i + 1] + (a[i + 1] == b[i] ? 2 : 1));
    cout << ans << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--)  solve();
    return 0;
}