#include <bits/stdc++.h>
#define LEN 45
#define N 100010
#define INF 0x3f3f3f3f
using namespace std;
string s;
int n;
int dp[LEN][N], val[LEN][LEN];

/*int get_val(int l, int r) {
    int res = 0;
    for(int i = l; i <= r; i++) {
        res *= 10;
        res += (s[i - 1] - '0');
        if(res > n)
            return n + 1;
    }
    return res;
}*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> s >> n;
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = -1;

    /*for(int i = 2; i <= s.size(); i++) 
        for(int j = 0; j <= n; j++) 
            if(j - (s[i - 1] - '0') >= 0)
                dp[i & 1][j] = min(dp[i & 1][j], dp[(i - 1) & 1][j - (s[i - 1] - '0')] + 1);*/

    memset(val, 0, sizeof(val));
    for(int i = 1; i <= (int)s.size(); i++) 
        for(int j = i; j <= (int)s.size(); j++)
            val[i][j] = min(n + 1, val[i][j - 1] * 10 + (s[j - 1] - '0'));
    for(int i = 1; i <= (int)s.size(); i++) {
        for(int j = 0; j <= n; j++) {
            for(int k = i - 1; k >= 0; k--) {
                int remain = j - val[k + 1][i];
                if(remain >= 0)
                    dp[i][j] = min(dp[i][j], dp[k][remain] + 1);
            }
        }
    }
    cout << (dp[(int)s.size()][n] < LEN ? dp[(int)s.size()][n] : -1);
    return 0;
}