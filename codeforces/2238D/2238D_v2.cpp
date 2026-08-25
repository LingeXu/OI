#include <bits/stdc++.h>
#define int long long
using namespace std;
int t, n;
void solve() {
    cin >> n;
    int cnt = 0, base = 0;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0)   base++;
        while(n % i == 0) {
            n /= i;
            cnt++;
        }
    }
    if(n != 1) {
        base++;
        cnt++;
    }
    cout << cnt + base - 1 << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while(t--)  solve();
    return 0;
}