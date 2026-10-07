#include <bits/stdc++.h>
using namespace std;
#define int long long
int t, n;
void solve() {
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] -= (i + 1);
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    /*cout << "Test:\n";
    for(int num : a)
        cout << num << ' ';
    cout << '\n';*/

    int m = (int)a.size();
    int ans = 1;
    for(int i = 0; i < m; ) {
        int j = i + 1;
        int cnt = 1;
        while(j < m && a[j] - a[i] == j - i) {
            cnt++;
            j++;
        }
        i = j;
        ans = max(ans, cnt);
    }
    cout << ans << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--)  solve();
    return 0;
}