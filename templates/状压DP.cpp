//状压DP: 状态用二进制表示集合, n 一般 <= 20
//常用位运算:
//  第 i 位: s >> i & 1;  置位: s | (1 << i);  清位: s & ~(1 << i)
//  枚举 s 的所有非空子集: for(t = s; t; t = (t - 1) & s)   (3^n 个)
//  全集: (1 << n) - 1;  补集: 全集 ^ s

//示例: TSP 旅行商, dp[mask][i] = 经过 mask 中的点(含起点)且最后停在 i 的最短路径
//需预定义: int d[N][N];  int dp[1 << 20][20];
memset(dp, 0x3f, sizeof(dp));
dp[1][0] = 0;                                            //从 0 出发, mask 只有点 0
for(int mask = 1; mask < (1 << n); mask++)
    for(int i = 0; i < n; i++)
        if((mask >> i & 1) && dp[mask][i] != INF)
            for(int j = 0; j < n; j++)
                if(!(mask >> j & 1))
                    dp[mask | (1 << j)][j] = min(dp[mask | (1 << j)][j], dp[mask][i] + d[i][j]);
int ans = INF;
for(int i = 0; i < n; i++)    ans = min(ans, dp[(1 << n) - 1][i] + d[i][0]);

//子集 DP 框架: dp[mask] 由 dp[sub](sub 为 mask 的真子集) 转移
//for(int mask = 0; mask < (1 << n); mask++)
//    for(int sub = mask; sub; sub = (sub - 1) & mask)
//        dp[mask] = min(dp[mask], dp[mask ^ sub] + cost(sub));
