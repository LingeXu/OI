#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, x, y;
        cin >> n >> x >> y;
        cout << min(x / 2 + y, n) << '\n';
    }
    return 0;
}