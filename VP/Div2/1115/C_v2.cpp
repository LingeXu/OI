#include <bits/stdc++.h>
#define int long long
using namespace std;
int t, n, m;
void solve() {
    cin >> n >> m;
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    vector<int> a(n * m);
    for(int i = 0; i < n * m; i++)
        cin >> a[i];
    int ans = m;
    multiset<int> s;
    for(int i = n - 1; i >= 0; i--) {
        for(int j = i * m; j < (i + 1) * m; j++) {
            if((int)s.size() < m) {
                s.insert(a[j]);
                continue;
            }
            if(a[j] > *s.begin()) {
                s.erase(s.begin());
                s.insert(a[j]);
            }
        }
        int aim = v[i], cur = 0;
        for(auto it = s.rbegin(); it != s.rend(); it++) {
            cur++;
            aim -= *it;
            if(aim <= 0)
                break;
        }
        ans = min(ans, cur);
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