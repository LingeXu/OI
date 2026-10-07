#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int mn = 0x3f3f3f3f;
        for(int i = 1; i <= 3; i++) {
            int x;
            cin >> x;
            mn = min(mn, x);
        }
        cout << n - mn << '\n';
    }
    return 0;
}