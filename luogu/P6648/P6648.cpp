#include <bits/stdc++.h>
#define N 3030
typedef long long ll;
using namespace std;
int n, k;
ll ans = 0;
int a[N][N], max_val[N][N][N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            cin >> a[i][j];
            max_val[i][j][1] = a[i][j];
        }
    }
    for(int sz = 2; sz <= k; sz++) 
        for(int i = 1; i + sz - 1 <= n; i++)
            for(int j = 1; j <= i; j++)
                max_val[i][j][sz] = max(max(max_val[i][j][sz - 1], max_val[i + 1][j][sz - 1]), max_val[i + 1][j + 1][sz - 1]);
    for(int i = 1; i + k - 1 <= n; i++)
        for(int j = 1; j <= i; j++)
            ans += 1LL * max_val[i][j][k];
    cout << ans;
    return 0;
}