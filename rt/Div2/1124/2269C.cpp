/*#include <bits/stdc++.h>
using namespace std;
#define int long long
int t, n, k;
void solve() {
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) 
        cin >> a[i];
    if(n == k) {
        cout << max(a[0], a[n - 1]) << '\n';
        return;
    }
    int ans = 0;
    if(n < 2 * k - 1) {
        for(int i = 0; i <= n - k; i++)
            ans += max(a[i], a[n - 1 - i]);
        cout << ans << '\n';
        return;
    }
    vector<int> b;
    for(int i = k - 1; i <= n - k; i++) 
        ans += a[i];
    for(int i = 0; i < k - 1; i++)
        b.push_back(a[i]);
    for(int i = n - k + 1; i < n; i++)
        b.push_back(a[i]);
    int m = (int)b.size();
    for(int i = 0; i < k - 1; i++)
        ans += max(b[i], b[m - 1 - i]);
    cout << ans << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--)  solve();
    return 0;
}*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
int t, n, k;
void solve() {
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    if(n == k) {
        cout << max(a[0], a[n - 1]) << '\n';
        return;
    }
    int ans = 0;
    if(n >= 2 * (k - 1)) {
        for(int i = 0; i < k - 1; i++)
            ans += max(a[i], a[n - 1 - i]);
        for(int i = k - 1; i <= n - k; i++)
            ans += a[i];
        cout << ans << '\n';
        return;
    }
    for(int i = 0; i <= n - k; i++)
        ans += max(a[i], a[n - 1 - i]);
    cout << ans << '\n';
    return;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--)  solve();
    return 0;
}