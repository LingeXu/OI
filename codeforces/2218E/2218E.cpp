#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
void solve() {
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int ans = 0;
    for(int i = 0; i < n - 1; i++) 
        for(int j = i + 1; j < n; j++)
            ans = max(ans, a[i] ^ a[j]);
    cout << ans << '\n';
}
signed main() {
    int t;
    cin >> t;
    while(t--)  solve();
}