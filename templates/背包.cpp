//01背包
int dp[M];
for(int i = 1; i <= n; i++)
    for(int j = m; j >= 0; j--)
        if(j - w[i] > = 0)
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);

//完全背包
int dp[M];
for(int i = 1; i <= n; i++)
    for(int j = w[i]; j <= m; j++)
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);