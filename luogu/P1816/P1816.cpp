#include <bits/stdc++.h>
#define N 100010
#define LOG 18
using namespace std;
int m, n;
int a[N], st[N][LOG];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> n;
    for(int i = 1; i <= m; i++) {
        cin >> a[i];
        st[i][0] = a[i];
    }
    for(int i = 1; i < LOG; i++)
        for(int j = 1; j + (1 << i) - 1 <= m; j++)
            st[j][i] = min(st[j][i - 1], st[j + (1 << (i - 1))][i - 1]);
    for(int i = 1; i <= n; i++) {
        int l, r;
        cin >> l >> r;
        int len = r - l + 1;
        int k = floor(log2(len));
        cout << min(st[l][k], st[r + 1 - (1 << k)][k]) << ' ';
    }
    return 0;
}