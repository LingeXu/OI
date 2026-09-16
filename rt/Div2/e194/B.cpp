#include <bits/stdc++.h>
#define int long long
using namespace std;
int t, x, y, k;
void solve() {
    cin >> x >> y >> k;
    if(y / x == 1) {
        cout << k * (y - x) << '\n';
        return;
    }
    int sum = 0, record1, record2;
    for(int i = 0; i < k; i++) {
        if((y + i) / (x + i) == 2) {
            record1 = (y + i) % (x + i);
            record2 = i;
            break;
        }
        sum += (y + i) % (x + i);
    }
    for(int i = record1; i >= 0 && record2 < k; i--) {
        sum += i;
        record2++;
    }
    if( k - 1 - y + 2 * x > 0)
        cout << sum + (y - x) *  (k - 1 - y + 2 * x) << '\n';
    else    cout << sum << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--)  solve();
    return 0;
}