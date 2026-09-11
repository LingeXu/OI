#include <bits/stdc++.h>
#define int long long
using namespace std;
int t, n, c, k;
void solve() {
    cin >> n >> c >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    int i = 0;
    while(i < n && a[i] <= c) {
        int add = min(c - a[i], k);
        a[i] += add;
        k -= add;
        c += a[i];
        i++;
    }
    cout << c << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--)  solve();
    return 0;
}