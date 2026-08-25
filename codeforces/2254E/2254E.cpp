#include <bits/stdc++.h>
#define int long long
using namespace std;
int t, n;
void solve() {
    cin >> n;
    vector<int> a(n);
    vector<bool> vis(n, false);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    int cur = 0;
    vector<int> ans;
    while((int)ans.size() < n) {
        int pos;
        auto it = a.begin(), tmp = a.begin();
        while(it != a.end()) {
            tmp = upper_bound(it, a.end(), -cur);
            if(tmp == a.end())  break;
            pos = tmp - a.begin();
            if(!vis[pos])   break;
            it = next(tmp);
        }
        if(tmp == a.end() || it == a.end()) {
            cout << -1 << '\n';
            return;
        }
        if(!vis[pos]) {
            vis[pos] = true;
            cur += a[pos];
            ans.push_back(cur);
        }
    }
    for(int i = 0; i < (int)ans.size(); i++)
        cout << ans[i] << ' ';
    cout << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while(t--)  solve();
    return 0;
}