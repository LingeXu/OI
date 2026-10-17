#include <bits/stdc++.h>
using namespace std;
#define int long long
int t, n;
void solve() {
    cin >> n;
    vector<int> a(n), b(n);
    int cnt_a = 0, cnt_b = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] % 2 == 1)   cnt_a++;
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
        if(b[i] % 2 == 1)   cnt_b++;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    bool ok = true;
    for(int i = 0; i < n; i++) {
        if(a[i] != b[i]) {
            ok = false;
            break;
        }
    }
    if(ok) {
        cout << "Yes\n";
        return;
    }
    bool has_a = false, has_b = false;
    for(int i = 0; i < n - 1; i++)
        if(a[i + 1] - a[i] == 1)
            has_a = true;
    for(int i = 0; i < n - 1; i++)
        if(b[i + 1] - b[i] == 1)
            has_b = true;
    if(!(has_a == true && has_b == true)) {
        cout << "No\n";
        return;
    }
    if(cnt_a == cnt_b) {
        cout << "Yes\n";
        return;
    }
    cout << "No\n";
    return;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--)  solve();
    return 0;
}