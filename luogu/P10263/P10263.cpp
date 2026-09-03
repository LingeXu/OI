#include <bits/stdc++.h>
#define int long long
#define K 1000010
using namespace std;
int n, m, k;
int sn[K], sm[K];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
        for(int j = i; j <= k; j += i)
            sn[j]++;
    for(int i = 1; i <= m; i++)
        for(int j = i; j <= k; j += i)
            sm[j]++;
    int ans = 0;
    for(int i = 1; i <= k; i++)
        ans += i * sn[i] * sm[i];
    cout << ans;
    return 0;
}