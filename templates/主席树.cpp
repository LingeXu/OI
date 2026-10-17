//主席树(可持久化权值线段树): 静态区间第 k 小 / 区间内某值的个数
//思想: root[i] = 前缀 [1..i] 的权值线段树版本, 两版本相减得到任意区间
//需预定义: int ls[CNT], rs[CNT], sum[CNT], root[N];  CNT = n * (log2(n) + 1) 左右, 常开 n << 5
//值域: 离散化到 [1, m]

int build(int l, int r) {                //建空树, 返回版本根(其实只有 root[0] 需要)
    int p = ++node_cnt;
    if(l == r)    return p;
    int mid = (l + r) >> 1;
    ls[p] = build(l, mid);
    rs[p] = build(mid + 1, r);
    return p;
}

int update(int pre, int l, int r, int pos) {   //在 pre 版本基础上 pos 处 +1, 返回新版本根
    int p = ++node_cnt;
    ls[p] = ls[pre];
    rs[p] = rs[pre];
    sum[p] = sum[pre] + 1;
    if(l == r)    return p;
    int mid = (l + r) >> 1;
    if(pos <= mid)    ls[p] = update(ls[pre], l, mid, pos);
    else    rs[p] = update(rs[pre], mid + 1, r, pos);
    return p;
}

int query(int u, int v, int l, int r, int k) { //u = root[l-1], v = root[r], 区间第 k 小
    if(l == r)    return l;                    //返回离散化值, 原值 = xs[l - 1]
    int mid = (l + r) >> 1;
    int cnt_left = sum[ls[v]] - sum[ls[u]];    //左值域内的个数
    if(k <= cnt_left)    return query(ls[u], ls[v], l, mid, k);
    return query(rs[u], rs[v], mid + 1, r, k - cnt_left);
}
//配套:
//1. 区间内 [x, y] 的个数: 两个版本的"按值域查个数"之差(或 rank 相减)
//2. 区间众数 / 出现次数 > len/2: 按"左值域个数"判走向
//3. 前缀版本在树上: root[u] = root[fa[u]] 上插入, 配合 LCA 可做树上路径第 k 小
