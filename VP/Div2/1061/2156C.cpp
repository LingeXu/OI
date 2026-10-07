#include <bits/stdc++.h>
using namespace std;
#define int long long
int t, n, k;
void solve() {
    cin >> n >> k;
    vector<int> a(n);
    unordered_map<int, int> mp;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    sort(a.begin(), a.end());
    int ans = a[0] / 4;
    for(int i = a[0] / 4 + 1; i <= a[k]; i++) {
        int cnt = mp[i] + mp[2 * i] + mp[3 * i];

        //cout << "i = " << i << ", cnt = " << cnt << '\n';
        //cout << '\n';

        auto it = lower_bound(a.begin(), a.end(), i * 4);
        if(it != a.end()) {
            int pos = it - a.begin();

            //cout << "pos = " << pos << '\n';
            //cout << '\n';

            cnt += n - pos;
        }

        //cout << "i = " << i << ", cnt = " << cnt << '\n';
        //cout << '\n';

        if(n - cnt <= k)    ans = i;
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