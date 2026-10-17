#include <bits/stdc++.h>
using namespace std;
int n;
void solve() {
    cin >> n;
    if(n % 3 == 0) {
        cout << 3 * (n - 1) << '\n';
        for(int rep = 0; rep < 3; rep++)
            for(int v = 2 * n - 1; v >= 2; v -= 2)
                cout << v << ' ';
    }
    else {
        cout << 3 * n << '\n';
        for(int rep = 0; rep < 3; rep++)
            for(int v = 2 * n; v >= 2; v -= 2)
                cout << v << ' ';
    }
    cout << '\n';
}
signed main() {
    int t;
    cin >> t;
    while(t--)  solve();
    return 0;
}
