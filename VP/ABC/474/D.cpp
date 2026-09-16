#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
        cin >> b[i];
    vector<int> ans(n + 1);
    bool ok = false;
    for(int i = 1; i <= n; i++) {
        if(a[i] > b[i]) {
            ans[i] = 1e18;
            ok = true;
        }
        else    ans[i] = 1;
    }
    if(!ok) {
        cout << "No";
        return 0;
    }
    else {
        cout << "Yes\n";
        for(int i = 1; i <= n; i++)
            cout << ans[i] << ' ';
    }
    return 0;
}