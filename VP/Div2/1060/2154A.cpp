#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        string s;
        cin >> n >> k >> s;
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] != '1')
                continue;
            bool pro = true;
            for(int j = max(0LL, i - k + 1); j <= i - 1; j++) {
                if(s[j] == '1') {
                    pro = false;
                    break;
                }
            }
            if(pro) {
                cnt++;
                continue;
            }
            else    continue;
        }
        cout << cnt << '\n';
        continue;
    }
}