#include <bits/stdc++.h>
#define M 1100
#define T 300003
using namespace std;
int m, s, t;
bool ok = false;
int dp[M][T];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> s >> t;
    memset(dp, -1, sizeof(dp));
    dp[m][t] = 0;
    for(int i = t; i >= 0; i--) {
        for(int j = 0; j < M; j++) {
            if(dp[j][i] == -1)  continue;
            dp[j + 4][i + 1] = max(dp[j + 4][i + 1], dp[j][i]);
            dp[j][i + 1] = max(dp[j][i + 1], dp[j][i] + 17);
            if(j - 10 >= 0) 
                dp[j - 10][i + 1] = max(dp[j - 10][i + 1], dp[j][i] + 60);
            if(dp[j + 4][i + 1] >= s || dp[j][i + 1] >= s || (dp[j - 10][i + 1] >= s && j - 10 >= 0)) {
                cout << "Yes" << '\n';
                cout << i + 1;
                return 0;
            }
        }
    }
    int max_dis = 0;
    for(int i = 0; i < M; i++)
        max_dis = max(max_dis, dp[i][0]);
    cout << "No" << '\n';
    cout << max_dis;
    return 0;
}