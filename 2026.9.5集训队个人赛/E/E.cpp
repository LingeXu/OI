#include <bits/stdc++.h>
using namespace std;
int t, n, k, a, b;
void solve() {
    cin >> n >> k >> a >> b;
    if(n == 1) {
        cout << k << '\n';
        return;
    }
    if(a > b)   swap(a, b);
    int diff = b - a;
    int need;
    if(!(diff & 1))   need = diff / 2 + 1;
    else    need = min(a + diff / 2 + 1, n - b + 1 + diff / 2 + 1);
    int remain = k - need;
    if(remain < 0) {
        cout << 0 << '\n';
        return;
    }
    cout << 1 + remain / 2 << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while(t--)  solve();
    return 0;
}