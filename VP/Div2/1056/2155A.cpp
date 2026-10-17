#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int s = n, b = 0;
        int ans = 0;
        while(!(s == 1 && b == 1)) {
            ans += s / 2 + b / 2;
            b = (b + 1) / 2 + s / 2;
            s = (s + 1) / 2;
            //cout << "b = " << b << ", s = " << s << '\n';
        }
        cout << ans + 1 << '\n';
    }

    return 0;
}