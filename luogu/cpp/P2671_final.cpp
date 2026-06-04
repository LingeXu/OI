#include <bits/stdc++.h>
#define N 100010
#define M 100010
const long long MOD = 10007;
typedef long long ll;
using namespace std;
int n, m, variety = 0;
ll ans = 0;
int a[N], color[N];
int cnt[M][2];
ll val_sum[M][2], color_sum[M][2], all_sum[M][2];
map<int, int> mp;
vector< pair<int, int>> c[M][2];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++)  cin >> a[i];
    for(int i = 0; i < n; i++) {
        cin >> color[i];
        cnt[color[i]][i % 2]++;
        if(cnt[color[i]][0] + cnt[color[i]][1] == 1) 
            mp[color[i]] = ++variety;
        ans += 1LL * (1LL * (cnt[color[i]][i % 2] - 1) * (i + 1) * a[i] % MOD + 1LL * val_sum[mp[color[i]]][i % 2] * (i + 1) % MOD + 1LL * color_sum[mp[color[i]]][i % 2] * a[i] % MOD + 1LL * all_sum[mp[color[i]]][i % 2] % MOD) % MOD;
        val_sum[mp[color[i]]][i % 2] += 1LL * a[i];
        color_sum[mp[color[i]]][i % 2] += 1LL * (i + 1);
        all_sum[mp[color[i]]][i % 2] += 1LL * a[i] * (i + 1);
    }
    cout << ans % MOD;
    return 0;
}