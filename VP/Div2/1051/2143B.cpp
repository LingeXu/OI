#include <bits/stdc++.h>
using namespace std;
#define int long long
int t, n, k;
bool cmp(int x, int y) {
    return x > y;
}
void solve() {
    cin >> n >> k;
    vector<int> a(n), b(k);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < k; i++)
        cin >> b[i];
    sort(a.begin(), a.end(), cmp);
    sort(b.begin(), b.end());
    int cur = -1;
    for(int i = 0; i < k; i++) {
        if(cur + b[i] >= n)
            break;
        a[cur + b[i]] = 0;
        cur += b[i];
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
        ans += a[i];
    cout << ans << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--)  solve();
    return 0;
}