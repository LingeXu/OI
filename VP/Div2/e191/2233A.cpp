#include <bits/stdc++.h>
using namespace std;
#define int long long
int t, n, x, y, z;
void solve() {
    cin >> n >> x >> y >> z;
    int ans1 = ( n % (x + y) == 0 ?( n / (x + y) ):(n / (x + y) + 1 ));
    if(x * z >= n) {
        cout << ans1 << '\n';
        return;
    }
    int ans2 = ((n + 10 * y * z) % (x + 10 * y) == 0) ? ((n + 10 * y * z) / (x + 10 * y)) : ((n + 10 * y * z) / (x + 10 * y) + 1);
    cout << min(ans1, ans2) << '\n';
    return;
}
signed main() {
    cin >> t;
    while(t--)  solve();
    return 0;
}