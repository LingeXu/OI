#include <bits/stdc++.h>
#define int long long
using namespace std;
int t, n, m, k;
void solve() {
    cin >> n >> m >> k;
    if (m < 2 * n) {            
        cout << k * (m - n) << '\n';
        return;
    }
    int sum = 0, cur = 0, record1, record2;
    while(cur < k) {
        if((m + cur) / (n + cur) > 2) {
            sum += (m + cur) % (n + cur);
            cur++;
        }
        else {
            record1 = cur;
            record2 = (m + cur) % (n + cur);
            break;
        }
    }
    if(cur == k) {
        cout << sum << '\n';
        return;
    }
    if(m - 2 * n + 1 >= k) {
        cout << sum + (2 * record2 - k + cur + 1) * (k - cur) / 2 << '\n';
        return;
    }
    cout << sum + (record2 + 1) * record2 / 2 + (k + 2 * n - m - 1) * (m - n) << '\n';
    return;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)  solve();
    return 0;
}