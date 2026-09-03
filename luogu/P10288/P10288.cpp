#include <bits/stdc++.h>
using namespace std;
int t, n, q;
void solve() {
    cin >> n;
    vector<int> a(n + 1);
    map<int, vector<int> > mp;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        mp[a[i]].push_back(i);
    }
    cin >> q;
    while(q--) {
        int l, r, x;
        cin >> l >> r >> x;
        if(mp.find(x) == mp.end()) {
            cout << 0 << '\n';
            continue;
        }
        auto L = lower_bound(mp[x].begin(), mp[x].end(), l), R = upper_bound(mp[x].begin(), mp[x].end(), r);
        cout << R - L << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while(t--)  solve();
    return 0;
}