#include <bits/stdc++.h>
using namespace std;
#define int long long
int t, n;
int nx(int x) {
    int res = 0;
    while(x > 0) {
        res += (x % 10) * (x % 10);
        x /= 10;
    }
    return res;
}
void solve() {
    cin >> n;
    int cnt1 = 0;
    vector<int> cnt2(8);
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        int cnt = 0;
        while(x != 4 && x != 1) {
            x = nx(x);

            //cout << "x = " << x << '\n';

            cnt++;
        }
        if(x == 1)    cnt1++;
        else    cnt2[cnt % 8]++;
    }
    int ans = cnt1 * (cnt1 - 1) / 2;
    for(int i = 0; i <= 7; i++) {

        //cout << "cnt2[i] = " << cnt2[i] << '\n';

        ans += cnt2[i] * (cnt2[i] - 1) / 2;
    }
    cout << ans << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--)  solve();
    return 0;
}