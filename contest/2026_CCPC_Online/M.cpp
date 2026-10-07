#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 998244353;
int t, n, x;
int fac[200001];
//int c[200001][200001];
void init() {
    fac[0] = 1;
    for(int i = 1; i <= 200000; i++) 
        fac[i] = fac[i - 1] * i % MOD;
}
/*int dfs(int x, int y) {
    if(c[x][y] != 0)    return c[x][y];
    return c[x][y] = (dfs(x - 1, y) + dfs(x - 1, y - 1)) % MOD;
}*/
int quick_pow(int a, int p) {
    int res = 1, base = a % MOD;
    while(p != 0) {
        if(p & 1)   res = res * base % MOD;
        p >>= 1;
        base = base * base % MOD;
    }
    return res;
}
int inv(int x) {
    return quick_pow(x, MOD - 2);
}
int c(int x, int y) {
    if(y > x) {
        cerr << "WRONG!\n";
        return -1;
    }
    if(y == 0)  return 1;
    if(x == y)  return 1;
    int a = fac[x], b = fac[y], c = fac[x - y];
    return a * inv(b) % MOD * inv(c) % MOD;
}
void solve() {
    cin >> n >> x;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    if(a[0] > x) {
        cout << 0 << '\n';
        return;
    }
    int smaller_than_x_and_odd = 0;
    auto it1 = upper_bound(a.begin(), a.end(), x);
    int pos1 = it1 - a.begin() - 1;
    for(int i = 0; i <= pos1; i++)
        smaller_than_x_and_odd = (smaller_than_x_and_odd + c(n - 1, i)) % MOD;
    int smaller_than_y_and_odd = 0;
    auto it2 = upper_bound(a.begin(), a.end(), x - (double)1 / 2);
    int pos2 = it2 - a.begin() - 1;
    for(int i = 0; i <= pos2; i++)
        smaller_than_y_and_odd = (smaller_than_y_and_odd + c(n - 1, i)) % MOD;
    int bigger_than_x_and_even = 0;
    for(int i = 0; i < n - 1; i++) {
        auto it = lower_bound(a.begin(), a.end(),  2 * x - a[i]);
        if(it == a.end())   continue;
        int j = max((int)(it - a.begin()), i + 1);
        bigger_than_x_and_even = (bigger_than_x_and_even + c(n + i - j, n - j - 1)) % MOD;
    }
    int bigger_than_z_and_even = 0;
    for(int i = 0; i < n - 1; i++) {
        auto it = lower_bound(a.begin(), a.end(),  2 * x + 1 - a[i]);
        if(it == a.end())   continue;
        int j = max((int)(it - a.begin()), i + 1);
        bigger_than_z_and_even = (bigger_than_z_and_even + c(n + i - j, n - j - 1)) % MOD;
    }

    /*cout << "pos1 = " << pos1 << '\n';
    cout << "pos2 = " << pos2 << '\n';
    cout << "smaller_than_x_and_odd = " << smaller_than_x_and_odd << '\n';
    cout << "smaller_than_y_and_odd = " << smaller_than_y_and_odd << '\n';
    cout << "bigger_than_x_and_even = " << bigger_than_x_and_even << '\n';
    cout << "bigger_than_z_and_even = " << bigger_than_z_and_even << '\n';*/

    cout << (((smaller_than_x_and_odd - smaller_than_y_and_odd + MOD) % MOD + bigger_than_x_and_even) % MOD - bigger_than_z_and_even + MOD) % MOD << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    cin >> t;
    while(t--)  solve();
    return 0;
}