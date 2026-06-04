#include<bits/stdc++.h>
#define N 110
#define M 110
const int MOD = 1e6 + 7;
using namespace std;
int n, m;
int a[N];
int dp[N][M];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= m; j++){
            for(int k = max(0, j - a[i]); k <= j; k++)
                dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
        }
    }
    cout << dp[n][m];
    return 0;
}