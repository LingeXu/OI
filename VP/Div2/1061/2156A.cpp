#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int ans = 0;
        while(n > 2) {
            int p = n / 3;
            ans += p;
            if(n % 3 == 0) {
                n = n / 3;
                continue;
            }
            if(n % 3 == 1) {
                n = n / 3 + 1;
                continue;
            }
            if(n % 3 == 2) {
                n = n / 3 + 2;
                continue;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}