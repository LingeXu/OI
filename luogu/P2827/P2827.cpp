#include <bits/stdc++.h>
#define N 100010
typedef long long ll;
using namespace std;
int n, m, q, u, v, t;
ll a[N];
queue<ll> q1, q2, q3;
bool cmp(ll a, ll b) {
    return a > b;
}
ll find_max() {
    ll x1 = (q1.empty() ? -LLONG_MAX : q1.front());
    ll x2 = (q2.empty() ? -LLONG_MAX : q2.front());
    ll x3 = (q3.empty() ? -LLONG_MAX : q3.front());
    if(x1 >= x2 && x1 >= x3) {
        q1.pop();
        return x1;
    }
    if(x2 >= x1 && x2 >= x3) {
        q2.pop();
        return x2;
    }
    q3.pop();
    return x3;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> q >> u >> v >> t;
    //double p = u / v;
    for(int i = 0; i < n; i++)  cin >> a[i];
    sort(a, a + n, cmp);
    for(int i = 0; i < n; i++)  q1.push(a[i]);
    for(int i = 1; i <= m; i++) {
        ll chosen = find_max() + 1LL * (i - 1) * q;
        if(i % t == 0)   cout << chosen << ' ';
        ll x = floor(chosen * u / v);
        ll y = chosen - x;
        q2.push(x - 1LL * i * q);
        q3.push(y - 1LL * i * q);
    }
    cout << '\n';
    for(int i = 1; i <= n + m; i++) {
        ll length = find_max() + m * q;
        if(i % t == 0)  cout << length << ' ';
    }
    return 0;
}