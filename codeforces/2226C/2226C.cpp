#include <bits/stdc++.h>
using namespace std;
#define int long long
int t, n;
vector<int> a(200005);
bool check(int x) {
    multiset<int> s(a.begin(), a.end());
    vector<int> need(x, true);
    for(int i = 0; i < x; i++) {
        if(s.count(i)) {
            s.erase(s.find(i));
            need[i] = false;
        }
    }
    for(int i = x - 1; i >= 0; i--) {
        if(!need[i])    continue;
        auto it = s.upper_bound(2 * i);
        if(it == s.end()) 
            return false;
        else    s.erase(it);
    }
    return true;
}
void solve() {
    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i++) 
        cin >> a[i];
    int l = 0, r = n, ans = -1;
    while(l <= r) {
        int mid = l + (r - l) / 2;
        if(check(mid)) {
            ans = mid;
            l = mid + 1;
        }
        else    r = mid - 1;
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