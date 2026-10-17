#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
void solve() {
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    int mx1, pref, mx2;
    for(int i = 0; i < n; i++) {
        if(i == 0) {
            mx1 = pref = a[i];
            continue;
        }
        a[i] = max(a[i] + pref, a[i] - pref);
        mx1 = max(mx1, a[i]);
        pref += a[i];
    }

    //cout << "mx1 = " << mx1 << '\n';

    for(int i = 0; i < n; i++) {
        if(i == 0) {
            mx2 = pref = b[i];
            continue;
        }
        mx2 = max(mx2, max(b[i] + pref, b[i] - pref));
        b[i] = min(b[i] + pref, b[i] - pref);
        pref += b[i];
    }

    //cout << "mx2 = " << mx2 << '\n';

    cout << max(mx1, mx2) << '\n';
}
signed main() {
    int t;
    cin >> t;
    while(t--)  solve();
    return 0;
}