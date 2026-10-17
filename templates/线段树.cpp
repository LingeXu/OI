//线段树: 区间加+求和(基础) / 区间赋值+区间加+求和(双lazy) / 线段树二分
//需预定义: int sum[4 * N], lazy[4 * N];  a[] 为原数组
//区间加 + 区间求和, build(1, 1, n) 入口
//注意: 多组数据时每组 build 前需 memset(lazy, 0, sizeof(lazy))

void build(int p, int l, int r) {
    if(l == r) {
        sum[p] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(2 * p, l, mid);
    build(2 * p + 1, mid + 1, r);
    sum[p] = sum[2 * p] + sum[2 * p + 1];
}

void push_down(int p, int l, int r) {
    if(lazy[p] == 0)    return;
    int mid = (l + r) >> 1;
    lazy[2 * p] += lazy[p];
    sum[2 * p] += lazy[p] * (mid - l + 1);
    lazy[2 * p + 1] += lazy[p];
    sum[2 * p + 1] += lazy[p] * (r - (mid + 1) + 1);
    lazy[p] = 0;
}

void update(int p, int l, int r, int ql, int qr, int val) {
    if(ql <= l && r <= qr) {
        sum[p] += val * (r - l + 1);
        lazy[p] += val;
        return;
    }
    push_down(p, l, r);
    int mid = (l + r) >> 1;
    if(ql <= mid)   update(2 * p, l, mid, ql, qr, val);
    if(qr > mid)    update(2 * p + 1, mid + 1, r, ql, qr, val);
    sum[p] = sum[2 * p] + sum[2 * p + 1];
}

int query(int p, int l, int r, int ql, int qr) {
    if(ql <= l && r <= qr)
        return sum[p];
    push_down(p, l, r);
    int res = 0;
    int mid = (l + r) >> 1;
    if(ql <= mid)   res += query(2 * p, l, mid, ql, qr);
    if(qr > mid)    res += query(2 * p + 1, mid + 1, r, ql, qr);
    return res;
}
//---------------- 进阶: 区间赋值 + 区间加 + 区间求和(双懒标记) ----------------
//需预定义: ll sum2[4 * N], addlz[4 * N];  ll setlz[4 * N];  setlz 用 -1 表示"无赋值标记"
//约定: 赋值标记优先于加标记(打赋值标记时清空加标记); 入口 build2(1, 1, n), 其余同理

void build2(int p, int l, int r) {
    setlz[p] = -1;
    addlz[p] = 0;
    if(l == r) {
        sum2[p] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build2(2 * p, l, mid);
    build2(2 * p + 1, mid + 1, r);
    sum2[p] = sum2[2 * p] + sum2[2 * p + 1];
}

void push_down2(int p, int l, int r) {
    int mid = (l + r) >> 1;
    if(setlz[p] != -1) {
        setlz[2 * p] = setlz[2 * p + 1] = setlz[p];
        addlz[2 * p] = addlz[2 * p + 1] = 0;
        sum2[2 * p] = setlz[p] * (mid - l + 1);
        sum2[2 * p + 1] = setlz[p] * (r - mid);
        setlz[p] = -1;
    }
    if(addlz[p]) {
        addlz[2 * p] += addlz[p];
        sum2[2 * p] += addlz[p] * (mid - l + 1);
        addlz[2 * p + 1] += addlz[p];
        sum2[2 * p + 1] += addlz[p] * (r - mid);
        addlz[p] = 0;
    }
}

void set2(int p, int l, int r, int ql, int qr, ll val) {   //区间赋值
    if(ql <= l && r <= qr) {
        setlz[p] = val;
        addlz[p] = 0;
        sum2[p] = val * (r - l + 1);
        return;
    }
    push_down2(p, l, r);
    int mid = (l + r) >> 1;
    if(ql <= mid)    set2(2 * p, l, mid, ql, qr, val);
    if(qr > mid)     set2(2 * p + 1, mid + 1, r, ql, qr, val);
    sum2[p] = sum2[2 * p] + sum2[2 * p + 1];
}

void add2(int p, int l, int r, int ql, int qr, ll val) {   //区间加
    if(ql <= l && r <= qr) {
        addlz[p] += val;
        sum2[p] += val * (r - l + 1);
        return;
    }
    push_down2(p, l, r);
    int mid = (l + r) >> 1;
    if(ql <= mid)    add2(2 * p, l, mid, ql, qr, val);
    if(qr > mid)     add2(2 * p + 1, mid + 1, r, ql, qr, val);
    sum2[p] = sum2[2 * p] + sum2[2 * p + 1];
}

ll query2(int p, int l, int r, int ql, int qr) {
    if(ql <= l && r <= qr)    return sum2[p];
    push_down2(p, l, r);
    int mid = (l + r) >> 1;
    ll res = 0;
    if(ql <= mid)    res += query2(2 * p, l, mid, ql, qr);
    if(qr > mid)     res += query2(2 * p + 1, mid + 1, r, ql, qr);
    return res;
}

//---------------- 线段树二分: 在整棵树上找第一个满足前缀条件的位置 ----------------
//例: 权值线段树求第 k 小(第 k 个 1); 不按区间拆, 直接在树上走
//int seg_kth(int p, int l, int r, int k) {
//    if(l == r)    return l;
//    int mid = (l + r) >> 1;
//    if(sum[2 * p] >= k)    return seg_kth(2 * p, l, mid, k);   //左子树够 k 个走左
//    return seg_kth(2 * p + 1, mid + 1, r, k - sum[2 * p]);     //否则去右, k 减去左子树个数
//}
//注意: 有懒标记时二分前要 push_down; 找"最靠左的 >= x 的位置"同理改判定条件
