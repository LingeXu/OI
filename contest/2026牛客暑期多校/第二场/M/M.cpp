#include <bits/stdc++.h>
using namespace std;
int t, n, m;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    for(int i = 1; i <= t; i++) {
        cin >> n >> m;
        if(m <= n - 1)
            cout << m * (m - 1) / 2 << '\n';
        else    cout << (n - 1) * (n - 2) / 2 - (m - (n - 1));
    }
    return 0;
}