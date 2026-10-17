#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++)
            cin >> a[i];
        unordered_map<int, set<int> > mp;
        int ans = 0;
        for(int i = 2; i < n - 2; i++) {
            ans += (int)mp[a[i] - a[i + 2] + a[i - 2]].size();
            if(i - 2 >= 2 && i - 2 < n - 2 && mp[a[i] - a[i + 2] + a[i - 2]].count(i - 2))
                ans--;
            if(i - 4 >= 2 && i - 4 < n - 2 && mp[a[i] - a[i + 2] + a[i - 2]].count(i - 4))
                ans--;
            mp[a[i] - a[i + 2] + a[i - 2]].insert(i);
        }
        cout << ans << '\n';
    }
    return 0;
}