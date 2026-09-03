#include <bits/stdc++.h>
#define int long long 
#define N 1010
const int MOD = 1e9 + 7;
using namespace std;
int t, n, m;
int c[N][N];
void init() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j <= i; j++) {
            if(j == 0) {
                c[i][j] = 1;
                continue;
            }
            if(i == j) {
                c[i][j] = 1;
                continue;
            }
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
        }
    }
}
void solve() {
    cin >> n >> m;
    vector<int> a(m);
    int sum = 0, ans = 1;
    for(int i = 0; i < m; i++) {
        cin >> a[i];
        sum += a[i];
    }
    for(int i = 0; i < m; i++) {
        ans = ans * c[sum][a[i]] % MOD;
        sum -= a[i];
    }
    cout << ans << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();

    /*cout << c[10][5] << '\n';
    cout << '\n';*/

    cin >> t;
    while(t--)  solve();
    return 0;
}