#include <bits/stdc++.h>
#define L 1010
using namespace std;
string s;
int dp[L][L];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    int n = s.size();
    memset(dp, 0x3f, sizeof(dp));
    for(int i = 1; i <= n; i++) 
        dp[i][i] = 0;
    for(int len = 2; len <= n; len++) {
        for(int l = 1; l + len - 1 <= n; l++) {
            int r = l + len - 1;
            if(s[l - 1] == s[r - 1]) {
                if(len == 2)
                    dp[l][r] = 0;
                else
                    dp[l][r] = dp[l + 1][r - 1];
            }
            else    dp[l][r] = min(dp[l + 1][r], dp[l][r - 1]) + 1;
        }
    }
    cout << dp[1][n];
    return 0;
}