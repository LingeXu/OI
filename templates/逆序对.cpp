//逆序对: i < j 且 a[i] > a[j] 的对数, BIT + 离散化 O(n log n)
//需预定义: 树状数组(见 树状数组.cpp): int tree[N];  add / presum;  原数组 a[1..n](值可重复)

ll count_inversion() {
    vector<int> xs(a + 1, a + n + 1);
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    memset(tree, 0, sizeof(tree));                       //多组数据时见 多组数据与时间戳.cpp
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        int rank = lower_bound(xs.begin(), xs.end(), a[i]) - xs.begin() + 1;
        ans += (i - 1) - presum(rank);                   //已插入中比 a[i] 大的个数
        add(rank, 1);
    }
    return ans;
}
//配套模型: 相邻交换排序最少次数 = 逆序对数; 二维偏序计数同理(按一维排序, 另一维 BIT)
//         严格大于改成 >= : presum(rank - 1) 处统计即可
