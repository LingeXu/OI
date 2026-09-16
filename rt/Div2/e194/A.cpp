#include <bits/stdc++.h>
using namespace std;
int t, n;
void solve() {
    cin >> n;
    int need = 0, have = 0;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(i == 0 || i == n - 1) {
            if(x == 1)
                need++;
        }
        else {
            if(x == 0)
                have++;
        }
    }
    if(have < need) {
        cout << -1 << '\n';
        return;
    }
    else {
        cout << need << '\n';
        return;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--)  solve();
    return 0;
}