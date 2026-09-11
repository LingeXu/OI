#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), presum(n + 1);
    for(int i = 0; i < n; i++) 
        cin >> a[i];
    sort(a.begin(), a.end());
    presum[0] = 0;
    for(int i = 0; i < n; i++)
        presum[i + 1] = presum[i] + a[i];
    int cur = 1;
    for(int i = 1; i <= m; i++) {
        cur <<= 1;
        int l = 0, r = n - 1, idx = n;
        while(l <= r) {
            int mid = (l + r) / 2;
            if(a[mid] > cur) {
                idx = mid;
                r = mid - 1;
            }
            else    l = mid + 1;
        }
        //cout << presum[idx] << ' ' << n - 1 - idx + 1 << ' ' << cur - 1 << '\n';
        int ans = presum[idx] + (n - 1 - idx + 1) * (cur - 1);
        cout << ans << ' ';
    }
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)  solve();
    return 0;
}