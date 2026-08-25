#include <bits/stdc++.h>
using namespace std;
void solve() {
    int m, r, c;
    cin >> m >> r >> c;
    if (c <= m) {
        cout << fixed << setprecision(12) << 1.0 << '\n';
        return;
    }
    double one_round = m;
    int remain = c - m;
    while (remain >= r + m) {
        one_round += m;
        remain -= (r + m);
    }
    if (remain >= r) {
        one_round += m;
        cout << fixed << setprecision(12) 
             << one_round / (c + m - (remain - r)) << '\n';
    } 
    else {
        cout << fixed << setprecision(12) 
             << max(one_round / c, (one_round + m) / (c + m - (remain - r))) << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}