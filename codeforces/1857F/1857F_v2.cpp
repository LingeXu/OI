#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int t, n, q;
pair<ll, ll> solve(ll x, ll y) {
    ll delta = x * x - 4 * y;
    ll x1 = (x + sqrt(delta)) / 2, x2 = (x - sqrt(delta)) / 2;
    return make_pair(x1, x2);
}
int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        vector<int> a(n);
        map<int, int> mp;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            mp[a[i]]++;
        }
        cin >> q;
        for(int i = 1; i <= q; i++) {
            ll x, y;
            cin >> x >> y;
            pair<ll, ll> solution = solve(x, y);
            if(solution.first + solution.second != x || solution.first * solution.second != y) {
                cout << 0 << ' ';
                continue;
            }
            else {
                if(solution.first == solution.second) {
                    cout << 1LL * mp[solution.first] * (mp[solution.first] - 1) / 2 << ' ';
                    continue;
                }
                else {
                    cout << 1LL * mp[solution.first] * mp[solution.second] << ' ';
                    continue;
                }
            }
        }
        cout << '\n';
    }
}