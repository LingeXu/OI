#include <bits/stdc++.h>
#define N 3003
#define LOG 15
typedef long long ll;
using namespace std;
int n, k;
ll ans = 0;
int a[N][N], st_up[N][N][2];
int GetAns(int x, int y) {
    int res = -1;
    int sz = log2(k);
    res = max(max(st_up[x][y][sz & 1], st_up[x + k - 1 - ((1 << sz) - 1)][y][sz & 1]), st_up[x + k - 1 - ((1 << sz) - 1)][y + k - 1 - ((1 << sz) - 1)][sz & 1]);
    if(k <= 3)  return res;
    res = max(res, max(max(st_up[][y][sz & 1]), ), st_up[x + (1 << sz)][y + (1 << (sz - 1))][sz & 1]);
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            cin >> a[i][j];
            st_up[i][j][0] = a[i][j];
        }
    }
    for(int sz = 1; sz <= log2(k); sz++) {
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= i; j++) {
                if(i + (1 << sz) - 1 > n)   continue;
                if(sz == 1) st_up[i][j][1] = max(max(a[i][j], a[i + 1][j]), a[i + 1][j + 1]);
                else {
                    st_up[i][j][sz & 1] = max(max(st_up[i][j][(sz - 1) & 1], st_up[i + (1 << (sz - 1))][j][(sz - 1) & 1]), st_up[i + (1 << (sz - 1))][j + (1 << (sz - 1))][(sz - 1) & 1]);
                    st_up[i][j][sz & 1] = max(max(max(st_up[i][j][sz & 1], st_up[i + (1 << (sz - 1))][j + (1 << (sz - 2))][(sz - 1) & 1]), st_up[i + (1 << (sz - 2))][j][(sz - 1) & 1]), st_up[i + (1 << (sz - 2))][j + (1 << (sz - 2))][(sz - 1) & 1]);
                }
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