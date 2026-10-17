#include <bits/stdc++.h>
using namespace std;
int n, k;
void solve() {
    cin >> n >> k;
    if(n * n - k == 1) {
        cout << "NO\n";
        return;
    }
    else    cout << "YES\n";
    for(int i = 1; i <= n * n; i++) {
        if(i <= n * n - k) {
            if(i == 1)
                cout << 'R';
            else if(i > 1 && i <= n)   cout << 'L';
            else    cout << 'U';
        }
        else    cout << 'D';
        if(i % n == 0)
            cout << '\n';
    }

}
int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}