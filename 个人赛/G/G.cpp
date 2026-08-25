#include <bits/stdc++.h>
#define int long long
using namespace std;
int t, n, sum = 0, mx = 0;
bool check(int x) {
    int aver = (sum + x) / (n - 1);
    return mx <= aver;
}
void solve() {
    cin >> n;
    vector<int> a(n + 1);
    sum = 0;
    mx = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
        mx = max(mx, a[i]);
    }
    int need = n - 1 - (sum % (n - 1));
    if(need == n - 1)   need = 0;
    int l = 0, r = 1e9, ans = -1;
    while(l <= r) {
        int mid = l + (r - l) / 2;
        if(check(mid * (n - 1) + need)) {
            ans = mid;
            r = mid - 1;
        }
        else    l = mid + 1;
    }
    cout << ans * (n - 1) + need << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while(t--)  solve();
    return 0;
}