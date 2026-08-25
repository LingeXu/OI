#include <bits/stdc++.h>
#define N 1000010
typedef long long ll;
const ll MOD = 998244353;
using namespace std;
int t, n;
string s;
int cnt[2], cnt_run[2];
ll fac[N];
void factorial_init(int x) {
    fac[0] = 1;
    for(ll i = 1; i <= x; i++)
        fac[i] = (fac[i - 1] * i) % MOD;
}
ll exgcd(ll a, ll b, ll& x, ll& y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll gcd = exgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - a / b * y1;
    return gcd;
}
bool get_modular_reverse(ll a, ll p, ll& x) {
    ll y;
    ll gcd = exgcd(p, a, y, x);
    if(gcd != 1)    return false;
    x %= p;
    if(x < 0)   x += p;
    return true;
}
ll combination(int n, int m) {
    if(n == -1 && m == -1)  return 1;
    if(m == 0)  return 1;
    if(n == m)  return 1;
    ll x1, x2;
    get_modular_reverse(fac[m], MOD, x1);
    get_modular_reverse(fac[n - m], MOD, x2);

    /*cout << x1 << '\n';
    cout << x2 << '\n';
    cout << '\n';*/

    return fac[n] * x1 % MOD * x2 % MOD; 
}
void solve() {
    cnt[0] = cnt[1] = 0;
    cnt_run[0] = cnt_run[1] = 0;
    cin >> n >> s;
    for(int i = 0; i < n; i++) {
        cnt[s[i] - '0']++;
        if(i == 0) {
            cnt_run[s[i] - '0']++;
            continue;
        }
        if(s[i] - '0' != s[i - 1] - '0')    cnt_run[s[i] - '0']++;
    }
    int x = max(cnt[0], cnt[1]) - 1;

    /*cout << cnt[0] << ' ' << cnt_run[0] << ' ' << cnt[1] << ' ' << cnt_run[1] << '\n';
    cout << '\n';*/

    factorial_init(x);

    /*for(int i = 0; i <= x; i++) 
        cout << fac[i] << ' ';
    cout << '\n';
    cout << '\n';*/

    cout << combination(cnt[0] - 1, cnt_run[0] - 1) * combination(cnt[1] - 1, cnt_run[1] - 1) % MOD << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while(t--)  solve();
    return 0;
}