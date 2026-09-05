//01背包
for(int i = 1; i <= n; i++)
    for(int j = m; j >= w[i]; j--)
        dp[j] = max(dp[j], dp[j - w[i]] + v[i]);

//完全背包
for(int i = 1; i <= n; i++)
    for(int j = w[i]; j <= m; j++)
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);