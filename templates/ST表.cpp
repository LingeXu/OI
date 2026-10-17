//ST表: 静态区间最值 RMQ, O(n log n) 预处理, O(1) 查询, 不支持修改
//需预定义: int st[LOG][N];   st[k][i] = [i, i+2^k-1] 区间的最大值
//入口: init(); query(l, r);  下标从 1 开始
#define LOG 20                  //需满足 2^LOG >= n

void init() {
    for(int i = 1; i <= n; i++)
        st[0][i] = a[i];
    for(int k = 1; (1 << k) <= n; k++)
        for(int i = 1; i + (1 << k) - 1 <= n; i++)
            st[k][i] = max(st[k - 1][i], st[k - 1][i + (1 << (k - 1))]);
}

int query(int l, int r) {
    int k = 31 - __builtin_clz(r - l + 1);   //log2(len) 向下取整; ll 用 63 - __builtin_clzll
    return max(st[k][l], st[k][r - (1 << k) + 1]);
}

//求最小值: 两处 max 改成 min
//其他场景: 静态区间 gcd(可重集), LCA 的 O(1) 欧拉序查询, 区间最大最小值差
