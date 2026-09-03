#include <bits/stdc++.h>
#define int long long
#define N 1010
const int MOD = 1e9 + 7;
using namespace std;
int t, n, m;
int fac[N];
void init() {
    fac[0] = 1;
    for(int i = 1; i <= 1000; i++)
        fac[i] = fac[i - 1] * i % MOD;
}
int exgcd(int m, int p, int& x, int& y) {
    if(m == 0) {
        x = 0;
        y = 1;
        return p;
    }
    int x1, y1;
    int gcd = exgcd(p % m, m, x1, y1);
    x = y1 - p / m * x1;
    y = x1;
    return gcd;
}
int c(int n, int m) {
    int x1, y1, x2, y2;
    exgcd(fac[m], MOD, x1, y1);
    exgcd(fac[n - m], MOD, x2, y2);

    /*cout << fac[n] << ' ' << x1 << ' ' << x2 << '\n';
    cout << '\n';*/

    return fac[n] * ((x1 + MOD) % MOD) % MOD * ((x2 + MOD) % MOD) % MOD;
}
void solve() {
    cin >> n >> m;
    vector<int> a(m);
    int sum = 0;
    for(int i = 0; i < m; i++) {
        cin >> a[i];
        sum += a[i];
    }
    if(sum == n) {
        int ans = 1;
        for(int i = 0; i < m; i++) {
            ans = (ans * c(sum, a[i])) % MOD;
            sum -= a[i];
        }
        cout << ans % MOD << '\n';
        return;
    }
    else {
        int record = sum - 1;
        int ans = 0;
        for(int i = 0; i < m; i++) {
            a[i]--;
            sum = record;
            int cur = 1;
            for(int j = 0; j < m; j++) {
                cur = (cur * c(sum, a[j])) % MOD;
                sum -= a[j];   
            }
            a[i]++;
            ans = (ans + cur) % MOD;
        }
        cout << ans % MOD << '\n';
        return;
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    init();

    /*for(int i = 0; i < 10; i++)
        cout << fac[i] << ' ';
    cout << '\n';

    int x, y;
    cout << exgcd(3, 5, x, y) << '\n';
    cout << x << ' ' << y << '\n';
    cout << '\n';
    
    cout << c(6, 3) << '\n';
    cout << '\n';*/

    while(t--)  solve();
    return 0;
}