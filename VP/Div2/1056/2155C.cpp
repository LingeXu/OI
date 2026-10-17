#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 676767677;
int t, n;
void solve() {
    cin >> n;
    vector<int> a(n + 1), pref_cnt(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    if(n == 1 && a[1] == 1) {
        cout << 2 << '\n';
        return;
    }
    if(n == 1 && a[1] != 1) {
        cout << 0 << '\n';
        return;
    }
    int ans = 0;
    pref_cnt[n] = a[n];
    pref_cnt[n - 1] = a[n] - 1;
    for(int i = n - 2; i >= 1; i--)
        pref_cnt[i] = a[i + 1] - n + i + pref_cnt[n] - pref_cnt[i + 1];
    bool ok1 = true;
    if(1 + n - 1 - (pref_cnt[n] - pref_cnt[1]) != a[1])
        ok1 = false;
    for(int i = 1; i <= n; i++) {
        if(pref_cnt[i] < 0 || pref_cnt[i] > i || pref_cnt[i] - pref_cnt[i - 1] > 1 || pref_cnt[i] - pref_cnt[i - 1] < 0) {
            ok1 = false;
            break;
        }
    }
    if(ok1) {
        /*for(int i = 1; i <= n; i++)
            cout << pref_cnt[i] << ' ';
        cout << '\n';*/
        ans++;
    }
    for(int i = 1; i <= n; i++)
        pref_cnt[i] = 0;
    pref_cnt[n] = a[n] - 1;
    pref_cnt[n - 1] = a[n] - 1;
    for(int i = n - 2; i >= 1; i--)
        pref_cnt[i] = a[i + 1] - n + i + pref_cnt[n] - pref_cnt[i + 1];
    bool ok2 = true;
    if(1 + n - 1 - (pref_cnt[n] - pref_cnt[1]) != a[1])
        ok2 = false;
    for(int i = 1; i <= n; i++) {
        if(pref_cnt[i] < 0 || pref_cnt[i] > i || pref_cnt[i] - pref_cnt[i - 1] > 1 || pref_cnt[i] - pref_cnt[i - 1] < 0) {
            ok2 = false;
            break;
        }
    }
    if(ok2) {
        /*for(int i = 1; i <= n; i++)
            cout << pref_cnt[i] << ' ';
        cout << '\n';*/
        ans++;
    }
    cout << ans << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while(t--)  solve();
    return 0;
}
