#include <bits/stdc++.h>
using namespace std;
int t, n;
void solve() {
    cin >> n;
    vector<int> a(n);
    int idx;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] == n)   idx = i;
    }
    int l = idx, r = idx, cur = n - 1;
    for(int i = cur; i >= 1; i--) {
        if(l > 0 && a[l - 1] == i) {
            l = l - 1;
            continue;
        }
        if(r < n - 1 && a[r + 1] == i) {
            r = r + 1;
            continue;
        }
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--)  solve();
    return 0;
}