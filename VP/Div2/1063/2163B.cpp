#include <bits/stdc++.h>
using namespace std;
int t, n;
string s;
void solve() {
    cin >> n;
    vector<int> a(n);
    int pos_1, pos_n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] == 1)   pos_1 = i;
        if(a[i] == n)   pos_n = i;
    }
    //cout << "pos_1 = " << pos_1 << '\n';
    //cout << "pos_n = " << pos_n << '\n';
    cin >> s;
    if(s[0] == '1' || s[n - 1] == '1' || s[pos_1] == '1' || s[pos_n] == '1') {
        cout << -1 << '\n';
        return;
    }
    cout << 5 << '\n';
    int mn = min(pos_1 + 1, pos_n + 1), mx = max(pos_1 + 1, pos_n + 1);
    cout << 1 << ' ' << mn << '\n';
    cout << 1 << ' ' << mx << '\n';
    cout << mn << ' ' << mx << '\n';
    cout << mn << ' ' << n << '\n';
    cout << mx << ' ' << n << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--)  solve();
    return 0;
}