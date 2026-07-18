#include <bits/stdc++.h>
#define N 55
#define M 55
#define T 2505
#define INF 0x3f3f3f3f
using namespace std;
int n, m, t, ans = 0;
int f[N][T], dp[N][T][M], red[N][M];
string s[N];
/*int solve(int id, int x) {
    string str = s[id];
    int l = s[id].size();
    vector<int> dp(l, INF);
    dp[0] = 1;
    for(int i = 1; i < l; i++) {
        if(str[i - 1] == str[i])
            dp[i] = dp[i - 1];
        else    dp[]
    }
}*/
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> t;
    for(int i = 1; i <= n; i++) {
        cin >> s[i];
        red[i][0] = 0;
        for(int j = 0; j < s[i].size(); j++) {
            if(s[i][j] == '0')
                red[i][j + 1] = red[i][j] + 1; 
            else    red[i][j + 1] = red[i][j];
        }
        
        //cout << red[i][s[i].size()] << ' ';

    }
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= t; j++) 
            for(int k = 1; k <= m; k++) 
                for(int x = j - 1; x <= k; x++)
                    dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][x] + max(red[i][k] - red[i][x], k - x - (red[i][k] - red[i][x])));
    memset(f, 0, sizeof(f));
    for(int i = 1; i <= n; i++) 
        for(int j = 0; j <= t; j++) 
            for(int k = 0; k <= j; k++) 
                f[i][j] = max(f[i][j], f[i - 1][k] + dp[i][j - k][m]);
    for(int i = 0; i <= t; i++)
        ans = max(ans, f[n][i]);
    cout << ans;
    return 0;
}