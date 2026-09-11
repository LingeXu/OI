#include <bits/stdc++.h>
using namespace std;
int t, n;
void solve() {
    cin >> n;
    int resp;
    for(int i = 1; i <= n - 1; i++) {
        cout << "? " << i * 2 - 1 << ' ' << i * 2 << endl;
        cin >> resp;
        if(resp == 1) {
            cout << "! " << i * 2 - 1 << endl;
            return;
        }
    }
    cout << "? " << 2 * n - 1 << ' ' << 1 << endl;
    cin >> resp;
    if(resp == 1) {
        cout << "! " << 2 * n - 1 << endl;
        return;
    }
    cout << "? " << 2 * n - 1 << ' ' << 2 << endl;
    cin >> resp;
    if(resp == 1) {
        cout << "! " <<  2 * n - 1  << endl;
        return;
    }
    cout << "! " << 2 * n << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--)  solve();
    return 0;
}
