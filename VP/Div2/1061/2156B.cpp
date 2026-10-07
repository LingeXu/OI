#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        bool all_A = true;
        for(char c : s) {
            if(c == 'B') {
                all_A = false;
                break;
            }
        }
        while(q--) {
            int x;
            cin >> x;
            if(all_A) {
                cout << x << '\n';
                continue;
            }
            int cnt = 0, cur = 0;
            while(x > 0) {
                if(s[cur] == 'A') {
                    x--;
                }
                else {
                    x /= 2;
                }
                cnt++;
                cur = (cur + 1) % n;
            }
            cout << cnt << '\n';
        }
    }
    return 0;
}