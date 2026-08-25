#include <bits/stdc++.h>
#define int long long
using namespace std;
int t, n, d;
void solve() {
    cin >> n >> d;
    vector<int> a(n);
    for(int i = 0; i < n; i++) 
        cin >> a[i];
    vector<int> b(n + 2 * d);
    for(int i = 0; i < d; i++)
        b[i] = a[n - (d - i)];
    for(int i = d; i < n + d; i++)
        b[i] = a[i - d];
    for(int i = n + d; i < n + 2 * d; i++) 
        b[i] = a[i - (n + d)];

    /*for(int i = 0; i < n + 2 * d; i++)
        cout << b[i] << ' ';
    cout << '\n';*/

    vector<int> prefix(n + 2 * d + 1);
    prefix[0] = 0;
    for(int i = 1; i <= n + 2 * d; i++) 
           prefix[i] = prefix[i - 1] + b[i - 1];
    int ans = 0;
    for(int i = d; i < n + d; i++) {
        int cur = (2 * d + 1) * b[i] - (prefix[i + d + 1] - prefix[i - d]);

        //cout << cur << ' ';

        ans += max(cur, 0LL);
    }

    //cout << '\n';
    
    cout << ans << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while(t--)  solve();
    return 0;
}