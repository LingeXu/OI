//树状数组: 单点改区间查 / 权值 BIT 求第 k 小
int lowbit(int x) {
    return x & (-x);
}

void add(int idx, int delta) {  //也可用于预处理
    for(int i = idx; i <= n; i += lowbit(i))    tree[i] += delta;
}   

ll presum(int pos) {
    ll res = 0;
    for(int i = pos; i > 0; i -= lowbit(i))    res += 1LL * tree[i];
    return res;
}
ll query(int l, int r) {
    return presum(r) - presum(l - 1);
}

//权值树状数组求第 k 小: tree 中存的是"个数"(每个位置 0/1 或计数), 返回第 k 个 1 的位置
//需满足 tree 的"前缀和"单调(即每个位置非负)
//需预定义: #define LOG 20   (2^LOG >= n, 从 LOG 往下跳)
int kth(int k) {
    int pos = 0;
    for(int i = LOG; i >= 0; i--) {
        int nxt = pos + (1 << i);
        if(nxt <= n && tree[nxt] < k) {
            k -= tree[nxt];
            pos = nxt;
        }
    }
    return pos + 1;                      //tree[pos+1] 贡献了第 k 个 1
}