#include <bits/stdc++.h>
#define N 404
#define M 800008
typedef long long ll;
using namespace std;
int n, ans = 0;
int s[N], f[N], dp[M];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) 
        cin >> s[i] >> f[i];
    memset(dp, -0x3f, sizeof(dp));

    /*dp[0][400000] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= 800000; j++) {
            if(j - s[i] >= 0)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - s[i]] + f[i]);
            else    dp[i][j] = dp[i - 1][j];
        }
    }*/

    dp[400000] = 0;
    for(int i = 1; i <= n; i++) {
        if(s[i] >= 0) {
            for(int j = 800000; j >= 0; j--) 
                if(j - s[i] >= 0)
                    dp[j] = max(dp[j], dp[j - s[i]] + f[i]);
        }
        else {
            for(int j = 0; j <= 800000; j++) 
                if(j - s[i] <= 800000)
                    dp[j] = max(dp[j], dp[j - s[i]] + f[i]);
        }
    }
    for(int i = 400000; i <= 800000; i++)
        if(dp[i] >= 0)
            ans = max(ans, i - 400000 + dp[i]);
    cout << ans;
    return 0;
}