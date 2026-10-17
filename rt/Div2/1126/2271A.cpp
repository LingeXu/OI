#include <bits/stdc++.h>
using namespace std;
int x, y;
void solve() {
    cin >> x >> y;
    if(y > x + 1) {
        cout << -1 << '\n';
        return;
    }
    if((x - y) % 2 == 0) {
        cout << x << '\n';
        return;
    }
    else    cout << x + 1 << '\n';
}
int main() {
    int t;
    cin >> t;
    while(t--)  solve();
    return 0;
}