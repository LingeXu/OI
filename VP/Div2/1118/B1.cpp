#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    int ans = n;
    auto it1 = lower_bound(a.begin(), a.end(), 2), it2 = upper_bound(a.begin(), a.end(), 2);
    ans += (it2 - it1);
    auto it = it2;
    while(it != a.end()) {
        if(*it % 2 == 0) {
            int cur = *it / 2;
            //cout <<  n - (lower_bound(a.begin(), a.end(), cur) - a.begin()) + (upper_bound(a.begin(), a.end(), 2 * cur) - lower_bound(a.begin(), a.end(), 2 * cur)) << '\n';
            ans = max(ans, (int)(n - (lower_bound(a.begin(), a.end(), cur) - a.begin()) + (upper_bound(a.begin(), a.end(), 2 * cur) - lower_bound(a.begin(), a.end(), 2 * cur))));
        }
        it = upper_bound(a.begin(), a.end(), *it);
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)  solve();
    return 0;
}