#include <bits/stdc++.h>
#define int long long
using namespace std;
int t, n, m;
void solve() {
    cin >> n >> m;
    vector<int> a(n), f(m + 1), s(m + 2), ans(m + 1);
    int sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        f[a[i]]++;
        sum += a[i];
    }
    for(int i = m; i >= 1; i--)
        s[i] = s[i + 1] + f[i];
    int i = 1;
    for(; i <= m && (1 << (i - 1)) < m; i++) {
        int edge = (1 << i) - 1;
        for(int x = 1; x <= m; x++) {
            int cur = 0;
            for(int j = 1; j * x <= m && j <= edge; j++) 
                cur += s[j * x];
            if((edge + 1) * x <= m)
                cur += f[(edge + 1) * x];
            ans[i] = max(ans[i], cur);
        }
    }
    for(; i <= m; i++)  ans[i] = sum;
    for(int i = 1; i <= m; i++)
        cout << ans[i] << " \n"[i == m]; 
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while(t--)  solve();
    return 0;
}