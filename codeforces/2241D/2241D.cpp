#include <bits/stdc++.h>
using namespace std;
#define int long long
int t, n;
void solve() {
    cin >> n;
    vector<int> a(n), b(n), diff(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int sum = 0;
    bool ok = true;
    for(int i = 0; i < n; i++) {
        cin >> b[i]; 
        diff[i] = b[i] - a[i];
        sum += diff[i];
        if(sum < 0)
            ok = false;
    }
    if(!ok) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    return;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--)  solve();
    return 0;
}