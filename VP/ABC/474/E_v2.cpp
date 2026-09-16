#include <bits/stdc++.h>
#define int long long
using namespace std;
int t, n;
struct inf {
    int a, b;
    bool operator<(const inf& other) const{
        return a - b < other.a - other.b || (a - b == other.a - other.b && a < other.a);
    }
};
void solve() {
    cin >> n;
    vector<inf> price(n);
    int mn = LLONG_MAX;
    for(int i = 0; i < n; i++) {
        cin >> price[i].a >> price[i].b;
        mn = min(price[i].a, mn);
    }
    if(n == 1) {
        cout << price[0].a << '\n';
        return;
    }
    sort(price.begin(), price.end());
    int ans = LLONG_MAX, base = 0;
    for(int i = 0; i < n; i++) 
        base += price[i].b;
    int prefix = 0;
    for(int i = 0; i <= (n + 1) / 2; i++) {
        if(i > 0)   prefix += price[i - 1].a - price[i - 1].b;

        //cout << "prefix = " << prefix << '\n';

        int need = max(0LL, n - 2 * i);
        ans = min(ans, base + prefix + need * mn);
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