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