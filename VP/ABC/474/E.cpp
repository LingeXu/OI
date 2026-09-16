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
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(i < (n + 1) / 2) {
            ans += price[i].a;
        }
        else {
            ans += price[i].b;
        }
    }
    if(n % 2 == 0) {
        for(int i = (n + 1) / 2 - 1; i > 0; i--)
            if(price[i].a > 2 * mn + price[i].b)
                ans -= (price[i].a - 2 * mn - price[i].b);
    }
    else {
        if(price[(n + 1) / 2 - 1].a > price[(n + 1) / 2 - 1].b + mn) {
            ans -= (price[(n + 1) / 2 - 1].a - price[(n + 1) / 2 - 1].b - mn);
            for(int i = (n + 1) / 2 - 2; i > 0; i--) 
                if(price[i].a > 2 * mn + price[i].b)
                    ans -= (price[i].a - 2 * mn - price[i].b);
        }
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