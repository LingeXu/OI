#include <bits/stdc++.h>
using namespace std;
#define int long long
int t, n;
void solve() {
    cin >> n;
    vector<int> a(n), pref_max(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(i == 0)  pref_max[i] = a[i];
        else    pref_max[i] = max(pref_max[i - 1], a[i]);
    }
    for(int i = 1; i < n; i += 2) {
        a[i] = pref_max[i];
    }
    int ans = 0;
    for(int i = 1; i < n; i += 2) {
        if(a[i] == a[i - 1]) {
            ans++;
            a[i - 1]--;
        }
        if(i + 1 < n) {
            ans += max(0LL, a[i + 1] - a[i] + 1);
            a[i + 1] = a[i] - 1;
            //cout << "ans = " << ans << '\n';
        }
    }
    cout << ans << '\n';
}
signed main() {
    int t;
    cin >> t;
    while(t--)  solve();
    return 0;
}