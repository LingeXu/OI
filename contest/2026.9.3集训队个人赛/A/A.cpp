#include <bits/stdc++.h>
#define N 200020
#define MOD 998244353
using namespace std;
int n, k;
int a[N], b[N], c[N], d[N], e[N], f[N];
int solve(int a, int b, int& x, int& y, int c) {
    if(a == 0) {
        x = 0;
        y = c / b;
        return b;
    }
    int x1, y1;
    int gcd = solve(b % a, a, x1, y1, c);
    x = y1 - b / a * x1;
    y = x1;
    return gcd;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for(int i = 0; i < n; i++) 
        cin >> a[i] >> b[i];
    for(int i = 0; i <= n - k; i++)
        c[i] = d[i] = 1;
    for(int i = 0; i < k; i++) {
        c[0] = c[0] * a[i] % MOD;
        d[0] = d[0] * b[i] % MOD;
    }
    for(int i = 1; i <= n - k; i++) {
        int x1, y1, x2, y2;
        solve(a[i - 1], MOD, x1, y1, 1);
        c[i] = c[i - 1] * a[i + k - 1] % MOD * ((x1 + MOD) % MOD) % MOD;
        solve(b[i - 1], MOD, x2, y2, 1);
        d[i] = d[i - 1] * b[i + k - 1] % MOD * ((x2 + MOD) % MOD) % MOD;
    }
    int x, y;
    for(int i = 0; i <= n - k; i++) {
        e[i] = (d[i] - c[i] + MOD) % MOD;
        f[i] = d[i];
        x = x * e[i] % MOD;
        y = y * f[i] % MOD;
    }
    int x1, y1;
    solve(y, MOD, x1, y1, x);
    cout << (x1 + MOD) % MOD;
    return 0;
}