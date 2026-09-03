#include <bits/stdc++.h>
using namespace std;
int t, n, q;
void solve() {
    cin >> n;
    vector<int> a(n);
    map<int, vector<int> > mp;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]].push_back(i);
    }
    cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;
        int ans = r - l + 1;
        for(int i = l - 1; i <= r - 1; i++) {
            auto it = upper_bound(mp[a[i]].begin(), mp[a[i]].end(), r - 1);
            int dis = it - lower_bound(mp[a[i]].begin(), mp[a[i]].end(), i);
            if(dis % 2 == 0) {
                ans -= *prev(it) - i + 1;
                i = *prev(it) + 1;
                continue;
            }
            else if(dis == 1) 
                continue;
            else {
                ans -= *prev(prev(it)) - i + 1;
                i = *prev(prev(it)) + 1;
                continue;
            }
        }
        cout << ans << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while(t--)  solve();
    return 0;
}