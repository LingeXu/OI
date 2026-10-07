#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        unordered_map<int, int> mp;
        for(int i = 0; i < 2 * n; i++) {
            int x;
            cin >> x;
            mp[x]++;
        }
        int cnt1 = 0, cnt2 = 0, cnt3 = 0;
        for(auto &[x, y] : mp) {
            if(y % 2 != 0) {
                cnt1++;
            }
            else if(y % 4 == 0) {
                cnt2++;
             
            }
            else {
                cnt3++;
            }
        }
        int ans = cnt1 + 2 * cnt2 + 2 * cnt3;

        //cout << "ans = " << ans << '\n';

        if(cnt1 > 0) {
            cout << ans << '\n';
            continue;
        }
        if(cnt2 % 2 == 0) {
            cout << ans << '\n';
            continue;
        }
        if(cnt2 % 2 == 1) {
            cout << ans - 2 << '\n';
        }
    }
    return 0;
}