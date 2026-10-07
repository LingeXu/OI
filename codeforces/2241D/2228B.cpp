#include <bits/stdc++.h>
using namespace std;
#define int long long
int t, n, x1, x2, k;
void solve() {
    cin >> n >> x1 >> x2 >> k;
    if(n <= 3) {
        cout << 1 << '\n';
        return;
    }
    int d1, d2;
    if(x1 > x2) {
        d1 = x1 - x2;
        d2 = n - x1 + x2;
    }
    else {
        d1 = x2 - x1;
        d2 = n - x2 + x1;
    }
    cout << min(d1, d2) + k << '\n';
    return;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--)  solve();
    return 0;
}