#include <bits/stdc++.h>
#define int long long
#define N 1000010
const int MOD = 998244353;
using namespace std;
int t, n;
string s;
int cnt[2], cnt_run[2], fac[N];
void factorial_init(int x) {
    fac[0] = 1;
    for(int i = 1; i <= x; i++)
        fac[i] = (fac[i - 1] * i) % MOD;
}
int exgcd(int a, int b, int& x, int& y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int gcd = exgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - a / b * y1;
    return gcd;
}
bool get_modular_reverse(int a, int p, int& x) {
    int y;
    int gcd = exgcd(p, a, y, x);
    if(gcd != 1)    return false;
    x %= p;
    if(x < 0)   x += p;
    return true;
}
int combination(int n, int m) {
    if(n == -1 && m == -1)  return 1;
    if(m == 0)  return 1;
    if(n == m) return 1;
    int x1, x2;
    if(!get_modular_reverse(fac[m] , MOD, x1))   cerr << "BUG\n";
    if(!get_modular_reverse(fac[n - m] , MOD, x2))    cerr << "BUG\n";
    return fac[n] * x1 % MOD * x2 % MOD;
}
void solve() {
    cnt[0] = cnt[1] = cnt_run[0] = cnt_run[1] = 0;
    cin >> n >> s;
    for(int i = 0; i < n; i++) {
        int num = s[i] - '0';
        cnt[num]++;
        if(i == 0) {    
            cnt_run[num]++;
            continue;
        }
        if(num != s[i - 1] - '0')   cnt_run[num]++;
    }
    int x = max(cnt[0], cnt[1]) - 1;
    factorial_init(x);
    cout << combination(cnt[0] - 1, cnt_run[0] - 1) * combination(cnt[1] - 1, cnt_run[1] - 1) % MOD << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while(t--)  solve();
    return 0LL;
}