//扫描线 + 线段树: 矩形面积并/周长并
//思想: 每个矩形拆成上下两条水平边, 按 y 排序扫描; 线段树维护当前被覆盖的 x 轴总长度
//需预定义: int cnt[4 * N], len[4 * N];  离散化后的竖线坐标 xs[1..m]
//叶子 [i, i] 代表 x 区间 [xs[i], xs[i+1]), 故线段树叶子只建到 m-1

struct Line {
    int y, x1, x2, tag;                  //tag = 1 为下边(进入), -1 为上边(离开)
};
bool cmp_line(Line p, Line q) {
    return p.y < q.y;
}

//len[p] = 节点区间内被覆盖的实际 x 长度(用 xs 换算), cnt[p] = 被完全覆盖的次数
void update(int p, int l, int r, int ql, int qr, int val) {
    if(ql <= l && r <= qr) {
        cnt[p] += val;                   //注意这里不做下传, len 直接在回溯时重算
    }
    else {
        int mid = (l + r) >> 1;
        if(ql <= mid)    update(2 * p, l, mid, ql, qr, val);
        if(qr > mid)     update(2 * p + 1, mid + 1, r, ql, qr, val);
    }
    if(cnt[p])    len[p] = xs[r + 1] - xs[l];            //整段被覆盖, 取实际长度
    else    len[p] = (l == r ? 0 : len[2 * p] + len[2 * p + 1]);
}

//预处理: 把每个矩形的 x1, x2 离散化到 xs[1..m]; 每条水平边转成 Line(离散化后的 x1, x2 下标)
ll area(vector<Line>& lines) {
    sort(lines.begin(), lines.end(), cmp_line);
    memset(cnt, 0, sizeof(cnt));
    memset(len, 0, sizeof(len));
    ll ans = 0;
    for(int i = 0; i + 1 < (int)lines.size(); i++) {
        update(1, 1, m - 1, lines[i].x1, lines[i].x2 - 1, lines[i].tag);
        ans += 1LL * len[1] * (lines[i + 1].y - lines[i].y);
    }
    return ans;
}
//周长并: 横边 = 每步 len[1] 的变化量(前后差绝对值), 竖边 = 2 * (相邻 y 差) * 当前不相交段数
//        维护"覆盖段数 num"与左右端是否覆盖, 竖边 = 2 * num * dy
