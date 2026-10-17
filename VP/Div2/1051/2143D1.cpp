#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1e9 + 7;
#define N 305
int t, n;
int ways[2][N][N];
void solve() {
    memset(ways, 0, sizeof(ways));
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    /*int m = 0, mp = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] > m) {

            ways[i % 2][a[i]][mp] = (ways[i % 2][a[i]][mp] + ways[(i + 1) % 2][m][mp]) % MOD;
            m = a[i];
            continue;
        }
        else if(a[i] <= m && a[i] > mp) {
            ways[i % 2][m][a[i]] = (ways[i % 2][m][a[i]] + ways[(i + 1) % 2][m][mp]) % MOD;
            mp = a[i];
            continue;
        }
        else    continue;
    }*/
    int m = 0, mp = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] > m)    m = a[i];
        else if(a[i] > mp && a[i] < m)  mp = a[i];
        ways[i % 2][0][0] = 1;
        for(int j = 0; j <= m; j++) 
            for(int k = 0; k <= mp && k < j; k++) 
                ways[i % 2][j][k] = ways[(i + 1) % 2][j][k];
        for(int j = 0; j <= m; j++) {
            for(int k = 0; k <= mp && k < j; k++) {
                if(a[i] > j) {
                    ways[i % 2][a[i]][k] = (ways[i % 2][a[i]][k] + ways[(i + 1) % 2][j][k]) % MOD;
                    continue;
                }
                else if(a[i] > k && a[i] < j) {
                    ways[i % 2][j][a[i]] = (ways[i % 2][j][a[i]] + ways[(i + 1) % 2][j][k]) % MOD;
                    continue;
                }
                else    continue;
            }
        }
    }
    int ans = 0;
    for(int i = 0; i <= n; i++)
        for(int j = 0; j < i; j++)
            ans = (ans + ways[(n + 1) % 2][i][j]) % MOD;
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