//数位DP: 统计 [0, n] 中满足数位条件的数的个数(含 0), 记忆化搜索框架
//需预定义: int digit[20];  ll dp[20][MAXS];   (MAXS 按状态大小开)
//用法: 区间 [L, R] 的答案 = count(R) - count(L - 1);  dp 只存 limit == false 的状态, 与 n 无关
//注意: 每次 count() 前 memset(dp, -1, sizeof(dp)) 即可(状态与 n 无关)

//示例状态: sum 为已填高位的数位和(改状态只需改 sum + i 与最后的判定)
ll dfs(int pos, int sum, bool limit) {
    if(pos == 0)    return sum == target;                 //填完, 判定状态是否合法
    if(!limit && dp[pos][sum] != -1)    return dp[pos][sum];
    int up = limit ? digit[pos] : 9;                      //贴上限则最高填 digit[pos]
    ll res = 0;
    for(int i = 0; i <= up; i++)
        res += dfs(pos - 1, sum + i, limit && i == up);
    if(!limit)    dp[pos][sum] = res;
    return res;
}

ll count(ll n) {
    int len = 0;
    while(n) {
        digit[++len] = n % 10;                            //digit[1] 为最低位
        n /= 10;
    }
    memset(dp, -1, sizeof(dp));
    return dfs(len, 0, true);
}

//常见状态: 是否含某数字(0/1)、各位和、%m 余数
//注意: 若条件受前导零影响(如"不含数字 0"), 需加 lead 参数区分"还没开始填数",
//      填 0 时若 lead 则不更新状态; 记忆化条件改为 !limit && !lead

