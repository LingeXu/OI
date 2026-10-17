//区间DP: 按区间长度递增转移, dp[l][r] 由更短的区间合并而来
//口诀: 长度在外层, 左端点中层, 断点内层
//需预定义: int dp[N][N];

for(int len = 2; len <= n; len++)                       //先枚举区间长度
    for(int l = 1; l + len - 1 <= n; l++) {
        int r = l + len - 1;
        for(int k = l; k < r; k++)                      //枚举断点(最后一步合并处)
            dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r] + cost(l, k, r));
    }
//经典: 石子合并(cost = 区间和, 前缀和维护)、回文串构造、括号匹配
//回文类区间 DP: 不用断点, 只由两端转移 dp[l][r] 与 dp[l+1][r], dp[l][r-1] 相关
//初始化: len == 1 的 dp[l][l] 单独赋值(如 0), 其余 INF
