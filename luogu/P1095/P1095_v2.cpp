#include <bits/stdc++.h>
using namespace std;
int m, s, t, remain_m;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> s >> t;
    vector<int> dp(t + 1, 0);
    remain_m = m;
    for(int i = 1; i <= t; i++) {
        if(remain_m - 10 >= 0) {
            remain_m -= 10;
            dp[i] = dp[i - 1] + 60;
        }
        else {
            remain_m += 4;
            dp[i] = dp[i - 1];
        }
    }
    for(int i = 1; i <= t; i++) {
        dp[i] = max(dp[i], dp[i - 1] + 17);
        if(dp[i] >= s) {
            cout << "Yes" << '\n';
            cout << i;
            return 0;
        }
    }
    cout << "No" << '\n';
    cout << dp[t];
    return 0;
}