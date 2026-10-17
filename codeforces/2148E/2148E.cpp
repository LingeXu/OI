#include <bits/stdc++.h>
using namespace std;
#define int long long
int t, n, k;
void solve() {
    cin >> n >> k;
    vector<int> a(n);
    unordered_map<int, int> cnt, cur;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    for(auto &[val, c] : cnt) {
        if(c % k != 0) {
            cout << 0 << '\n';
            return;
        }
    }
    int ans = 0, pre = 0;
    for(int i = 0; i < n; i++) {
        if(i != 0)
            cur[a[i - 1]]--;
        int j;
        for(j = pre; j < n; j++) {
            cur[a[j]]++;
            if(cur[a[j]] * k > cnt[a[j]]) {
                ans += j - i;
                cur[a[j]]--;
                pre = j;
                break;
            }
        }
        if(j == n) {
            ans += (n - i) * (n - i + 1) / 2;
            cout << ans << '\n';
            return;
        }
        //cout << "ans = " << ans << '\n';
    }
    cout << ans << '\n';
    return;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--)
        solve();
    return 0;
}