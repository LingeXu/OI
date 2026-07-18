#include <bits/stdc++.h>
#define N 250
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
        f[i][i] = a[i];
        ans = max(ans, a[i]);
    }
    for(int len = 2; len <= n; len++) {
        for(int l = 1; l + len - 1 <= n; l++) {
            int r = l + len - 1;
            for(int k = l; k < r; k++) {
                if(f[l][k] == f[k + 1][r] && f[l][k] != 0) {
                    f[l][r] = f[l][k] + 1;
                    ans = max(ans, f[l][r]);
                    break;
                }
            }
        }
    }
    cout << ans;
    return 0;
}