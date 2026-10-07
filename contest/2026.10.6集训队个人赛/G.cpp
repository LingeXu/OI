#include <bits/stdc++.h>
using namespace std;
#define N 1000005
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n + 1), pre(n + 1);
    unordered_map<int, int> mp;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(!mp.count(a[i]))
            pre[i] = 0;
        else    pre[i] = mp[a[i]];
        mp[a[i]] = i;
    }
    int mx = 0;
    vector< vector<int> > dp(n + 1, vector<int>(2));
    dp[0][0] = dp[0][1] = -1;
    for(int i = 1; i <= n; i++) {
        dp[i][0] = max(dp[pre[i]][0], dp[pre[i]][1]) + 1;
        dp[i][1] = mx + 1;
        mx = max(mx, dp[i][0]);
        /*cout << "i = " << i << '\n';
        cout << "dp[i][0] = " << dp[i][0] << '\n';
        cout << "dp[i][1] = " << dp[i][1] << '\n';
        cout << '\n';*/
    }
    cout << mx;
    return 0;
}