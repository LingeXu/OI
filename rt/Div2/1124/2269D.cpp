#include <bits/stdc++.h>
using namespace std;
int t, n, q;
void solve() {
    cin >> n >> q;
    vector<int> a(n), add(n, 0);
    int ans = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        int cnt = 0;
        for(int j = 0; j < 4; j++) 
            if((a[i] >> j) & 1 != 0)
                cnt++;
        if(cnt % 2 == 0) {
            add[i] = 1;
            ans++;
        }
    }
    cout << ans << ' ';
    while(q--) {
        int p, x;
        cin >> p >> x;
        ans -= add[p - 1];
        int cnt = 0;
        for(int j = 0; j < 4; j++)
            if((x >> j) & 1 != 0)
                cnt++;
        if(cnt % 2 == 0) {
            add[p - 1] = 1;
            ans++;
        }
        else    add[p - 1] = 0;
        cout << ans << ' ';
    }
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--)  solve();
    return 0;
}