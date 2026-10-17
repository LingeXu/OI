//莫队: 离线处理区间查询, 左右指针共移动 O(n * sqrt(q)) 次
//适用: 答案能从相邻区间 O(1) 增删维护(区间不同颜色数等), 且无修改
//需预定义: struct Query { int l, r, id; } q[M];  int block, cur_l, cur_r;  ll cur_ans;
//         void add(int pos);  void del(int pos);   (维护 cur_ans, 按题目实现)
//入口: block = sqrt(n); sort(q + 1, q + m + 1, cmp); mo();

bool cmp(Query x, Query y) {
    if(x.l / block != y.l / block)    return x.l < y.l;
    return (x.l / block) & 1 ? x.r > y.r : x.r < y.r;   //奇偶排序: 偶数块 r 增, 奇数块 r 减
}

void mo() {
    sort(q + 1, q + m + 1, cmp);
    cur_l = 1;
    cur_r = 0;                           //初始空区间
    cur_ans = 0;
    for(int i = 1; i <= m; i++) {
        while(cur_l > q[i].l)    add(--cur_l);    //先扩再缩, 保证指针不交叉
        while(cur_r < q[i].r)    add(++cur_r);
        while(cur_l < q[i].l)    del(cur_l++);
        while(cur_r > q[i].r)    del(cur_r--);
        ans[q[i].id] = cur_ans;
    }
}
//带修改莫队: 加时间维, 块大小取 n^(2/3); 树上莫队: 欧拉序转括号序列
