#include <bits/stdc++.h>
#define int long long
using namespace std;
int t, n;
void solve() {
    cin >> n;
    multiset<int> a;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.insert(x);
    }
    int cur = 0;
    vector<int> ans;
    while((int)ans.size() < n) {
        auto it = a.upper_bound(-cur);
        if(it == a.end()) {
            cout << -1 << '\n';
            return;
        }
        cur += *it;
        ans.push_back(cur);
        a.erase(it);
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