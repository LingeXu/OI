#include <bits/stdc++.h>
#define N 50050
#define LOG 17
using namespace std;
int n, m, ans = 0;
int p[N];
int fa[N][LOG], val[N][N];
void init() {
    for(int i = 1; i <= n; i++)
        fa[i][0] = p[i];
    for(int i = 1; i < LOG; i++) 
        for(int j = 1; j <= n - (1 << i) + 1; j++) 
            fa[j][i] = fa[j][i - 1] + fa[j + (1 << (i - 1))][i - 1];
}
int GetSum(int l, int m) {
    if(val[l][m] != 0)
        return val[l][m];
    int log = 0, now = 1;
    while(now <= m) {
        now <<= 1;
        log++;
    }
    log--;
    return val[l][m] = fa[l][log] + GetSum(l + (1 << log), m - (1 << log));
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> p[i];

    /*
    int j = 0, cur = 0;
    for(int i = 1; i <= n; i++) {
        while(j <= n && j - i + 1 < m) {
            j++;
            cur += p[j];
        }
        ans = max(ans, cur);
        cur -= p[i];
    }
    cout << ans;
    */

    init();
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n - i + 1; j++)
            ans = max(ans, GetSum(j, i));
    cout << ans;
    return 0;
}