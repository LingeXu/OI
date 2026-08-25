#include <bits/stdc++.h>
#define N 10010
using namespace std;
int t, n, m;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while(t--) {
        cin >> n >> m;
        if(n == m) {
            cout << n + m << '\n';
            continue;
        }
        if(n >= m)  swap(n, m);
        int ans = 2 * n;
        ans += (2 * (m - n) - 1);
        cout << ans << '\n';
    }
    return 0;
}