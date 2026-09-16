#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    unordered_map<int, int> pre1;
    vector<int> a(n + 1), pre2(n + 1, -1), dp(n + 1);
    int cur = 0;
    pre1[0] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        cur = (cur + a[i]) % k;
        if(!pre1.count(cur))    pre2[i] = -1;
        else    pre2[i] = pre1[cur];
        pre1[cur] = i;
    }
    if(k == 1) {
        cout << n;
        return 0;
    }

    /*for(int i = 1; i <= n; i++)
        cout << "pre = " << pre2[i] << '\n';*/

    dp[0] = 0;
    for(int i = 1; i <= n; i++) {
        int last = pre2[i];
        if(last != -1)
            dp[i] = max(dp[i - 1], dp[last] + 1);
        else    dp[i] = dp[i - 1];
    }

    /*for(int i = 1; i <= n; i++)
        cout << "i = " << i << ", dp[i] = " << dp[i] << '\n';*/

    cout << dp[n];
    return 0;
}