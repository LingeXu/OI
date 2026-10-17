#include <bits/stdc++.h>
using namespace std;
#define int long long
int t, n, k;
void solve() {
    cin >> n >> k;
    vector<int> a(n), pref_sum(n + 1);
    unordered_map<int, vector<int> > mp;
    mp[0].push_back(-1);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        pref_sum[i + 1] = (pref_sum[i] + a[i]) % k;
        mp[pref_sum[i + 1]].push_back(i);
    }
    int ans = 0;
    for(auto & [val, v] : mp) {
        int l = (int)v.size();
        //cout << "l = " << l << '\n';
        if(l == 1) 
            continue;
        for(int i = 0; i < l; i++) {
            int pos = upper_bound(v.begin(), v.end(), v[i] + k) - v.begin();
            //cout << "pos = " << pos << '\n';
            ans += l - pos;
            //cout << "ans = " << ans << '\n';
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