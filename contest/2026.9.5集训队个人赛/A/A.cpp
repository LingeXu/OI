#include <bits/stdc++.h>
using namespace std;
int t;
void solve() {
    long long n, m, a, b, r;
    cin >> n >> m >> a >> b >> r;
    __int128 carry = 0, ans = 0;
    for (long long s = 1; s <= n + m - 1; s++) {
        long long cnt = min(min(s, n), min(m, n + m - s));
        __int128 v = (__int128)a * b * cnt + carry;
        ans += v % r;
        carry = v / r;                    
    }
    while (carry > 0) { ans += carry % r; carry /= r; }
    if (ans == 0) { cout << "0\n"; return; }
    vector<int> out;
    while (ans > 0) { out.push_back((int)(ans % r)); ans /= r; }
    for (int i = (int)out.size() - 1; i >= 0; i--) cout << out[i];
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while(t--)  solve();
}
