#include <bits/stdc++.h>
#define N 3030
#define LOG 15
typedef long long ll;
using namespace std;
int n, k;
ll ans = 0;
int a[N][N], st_up[N][N][LOG], st_down[N][N][LOG];
int GetAns(int x, int y) {
    int sz = log2(k);
    return max(max(st_up[x][y][sz], st_up[x + k - 1 - ((1 << sz) - 1)][y][sz]), st_up[x + k - 1 - ((1 << sz) - 1)][y + k - 1 - ((1 << sz) - 1)][sz]);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            cin >> a[i][j];
            st_up[i][j][0] = st_down[i][j][1] = a[i][j];
        }
    }
    for(int sz = 1; sz < LOG; sz++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= i; j++) {
                if(sz == 1 && i + 1 <= n) {
                    st_up[i][j][1] = max(max(a[i][j], a[i + 1][j]), a[i + 1][j + 1]);
                    continue;
                }
                if(i - ((1 << sz) - 2) >= 1 && j - ((1 << sz) - 2) >= 1 && j <= i - ((1 << sz) - 2))
                    st_down[i][j][sz] = max(max(max(st_down[i][j][sz - 1], st_down[i - (1 << (sz - 1))][j - (1 << (sz - 1))][sz - 1]), st_down[i - (1 << (sz - 1))][j][sz - 1]), st_up[i - ((1 << sz) - 2)][j - ((1 << (sz - 1)) - 1)][sz - 1]);
                if(i + (1 << sz) - 1 <= n)
                    st_up[i][j][sz] = max(max(max(st_up[i][j][sz - 1], st_up[i + (1 << (sz - 1))][j][sz - 1]), st_up[i + (1 << (sz - 1))][j + (1 << (sz - 1))][sz - 1]), st_down[i + (1 << sz) - 2][j + (1 << (sz - 1)) - 1][sz - 1]);
            }
        }
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= i; j++)
            if(i + k - 1 <= n)
                ans += 1LL * GetAns(i, j);
    cout << ans;
    return 0;
}