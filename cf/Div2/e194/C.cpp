#include <bits/stdc++.h>
#define MASK 31
#define int long long
using namespace std;
int t, x, y;
void solve() {
    cin >> x >> y;
    cout << x + y << ' ';
    int remain = x;
    int tmp = 0;
    for(int i = MASK; i >= 0; i--) {
        int num = ((x + y) >> i) & 1;
        if(num == 1) {
            if(remain - (1 << i) >= 0) {
                remain -= (1 << i);
                tmp += (1 << i);
            }
        }
    }
    cout << x - tmp << '\n';
    return;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--)  solve();
    return 0;
}