#include <bits/stdc++.h>
using namespace std;
#define int long long
int gcd(int x, int y) {
    if(x == 0)  return y;
    if(y == 0)  return x;
    return gcd(y % x, x);
}
int t, n, m, a, b;
void solve() {
    cin >> n >> m >> a >> b;
    if(gcd(n, a) != 1 || gcd(m, b) != 1) {
        cout << "NO\n";
        return;
    }
    if(gcd(n, m) > 2) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--)  solve();
    return 0;
}