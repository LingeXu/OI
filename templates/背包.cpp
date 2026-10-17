//01背包
for(int i = 1; i <= n; i++)
    for(int j = m; j >= w[i]; j--)
        dp[j] = max(dp[j], dp[j - w[i]] + v[i]);

//完全背包
for(int i = 1; i <= n; i++)
    for(int j = w[i]; j <= m; j++)
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);

//多重背包: 每种物品有 s[i] 件
//二进制拆分: s[i] 拆成 1, 2, 4, ..., 2^t, 余数 共 O(log s) 捆, 每捆当一件 01 背包物品
//复杂度 O(n * m * log s); 数据大到拆分也过不了时再上单调队列优化(见 单调队列.cpp)
vector< pair<int, int> > goods;          //(重量, 价值)
for(int i = 1; i <= n; i++) {
    int cnt = s[i], k = 1;
    while(cnt >= k) {
        goods.push_back({w[i] * k, v[i] * k});
        cnt -= k;
        k <<= 1;
    }
    if(cnt)    goods.push_back({w[i] * cnt, v[i] * cnt});
}
for(auto& g : goods)
    for(int j = m; j >= g.first; j--)
        dp[j] = max(dp[j], dp[j - g.first] + g.second);