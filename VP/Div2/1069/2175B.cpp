#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, l, r;
        cin >> n >> l >> r;
        for(int i = 1; i <= n; i++) {
            if(i == r) {
                cout << ((r - 1) ^ (l - 1)) << ' ';
                continue;
            }
            if(i == r + 1) {
                cout << ((l - 1) ^ (r + 1)) << ' ';
                continue;
            }
            else    cout << (i ^ (i - 1)) << ' ';
        }
        cout << '\n';
    }
    return 0;
}