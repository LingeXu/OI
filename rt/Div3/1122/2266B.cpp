#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int t;
    cin >> t;
    while(t--) {
        int a, b, c;
        cin >> a >> b >> c;
        if(a >= b) {
            cout << a + c - b << '\n';
            continue;
        }
        else {
            cout << max(a + c - b, b - a) << '\n';
            continue;
        }
    }
    return 0;
}