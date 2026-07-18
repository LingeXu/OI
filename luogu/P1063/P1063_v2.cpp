#include <bits/stdc++.h>
#define N 220
#define INF 0x3f3f3f3f
using namespace std;
int n, ans = 0;
int a[N], f[N][N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
    }
    memset(f, 0, sizeof(f));
    for(int len = 2; len <= n; len++) {
        for(int l = 1; l + len - 1 < 2 * n; l++) {
            int r = l + len - 1;
            for(int k = l; k < r; k++)
                f[l][r] = max(f[l][r], f[l][k] + f[k + 1][r] + a[l] * a[k + 1] * a[r + 1]);
        }
    }
    for(int i = 1; i <= n; i++)
        ans = max(ans, f[i][i + n - 1]);
    cout << ans;
    return 0;
}