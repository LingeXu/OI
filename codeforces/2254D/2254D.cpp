#include <bits/stdc++.h>
using namespace std;
#define int long long
int t, n;
void solve() {
    cin >> n;
    vector<int> a(n, -1), b(n);
    unordered_map< int, vector<int> > mp;
    for(int i = 0; i < n; i++) {
        cin >> b[i];
        mp[b[i]].push_back(i);
    }
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    if(b[0] != 0) {
        cout << -1 << '\n';
        return;
    }
    int pre_x, pre_a = 0;
    for(int x : b) {
        if(x == 0) {
            pre_x = 0;
            continue;
        }
        if((x - pre_x) % (int)mp[pre_x].size() != 0) {
            cout << -1 << '\n';
            return;
        }
        int cur = (x - pre_x) / (int)mp[pre_x].size();
        if(cur <= pre_a) {
            cout << -1 << '\n';
            return;
        }
        for(int i : mp[pre_x]) 
            a[i] = cur;
        pre_a = cur;
        pre_x = x;
    }
    int mx = 0;
    for(int i = 0; i < n; i++)
        mx = max(mx, a[i]);
    for(int i = 0; i < n; i++)
        if(a[i] == -1)
            a[i] = mx + 1;
    for(int i = 0; i < n; i++)
        cout << a[i] << ' ';
    cout << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--)  solve();
    return 0;
}