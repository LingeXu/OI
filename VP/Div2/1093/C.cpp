#include <bits/stdc++.h>
using namespace std;
int t, x, y;
void solve() {
    cin >> x >> y;
    int a, b;
    int aim = x + 2 * y;
    for(int i = 1; 2 * i * i <= aim; i++) {
        if((aim - i) % (2 * i + 1) == 0) {
            int a = i;
            int b = (aim - a) / (2 * a + 1);
            if(abs(a - b) <= x) {
                cout << a << ' ' << b << '\n';
                return;
            }
        }
    }
    cout << -1 << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--)  solve();
    return 0;
}