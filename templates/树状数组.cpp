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