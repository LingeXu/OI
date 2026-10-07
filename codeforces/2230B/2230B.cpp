#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int t;
    cin >> t;
    while(t--) {
        string s, ob;   
        cin >> s;
        int ans = 0, cnt_2 = 0;
        for(char c : s) {
            if(c == '4') {
                ans++;
                continue;
            }
            if(c == '2')    cnt_2++;
            ob += c;
        }
        if(ans == (int)s.size() || cnt_2 == 0) {
            cout << ans << '\n';
            continue;
        }
        int m = (int)ob.size(), ans_add = min(cnt_2, m - cnt_2);
        if(m == cnt_2) {
            cout << ans << '\n';
            continue;
        }
        vector<int> pref_sum(m + 1);
        for(int i = 0; i < m; i++) {
            if(ob[i] == '2')    pref_sum[i + 1] = pref_sum[i] + 1;
            else    pref_sum[i + 1] = pref_sum[i];
        }
        for(int i = 0; i < m; i++) {
            int cur = pref_sum[i + 1] + m - i - 1 - (cnt_2 - pref_sum[i + 1]);
            ans_add = min(ans_add, m - cur);
        }
        cout << ans + ans_add << '\n';
    }
}