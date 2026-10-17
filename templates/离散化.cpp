//离散化: 把大范围的值压缩到 [1, m] 且保持大小关系
//需预定义: vector<int> a(原始数组), xs(备份数组)
//场景: 值当数组下标(树状数组/线段树/桶)、扫描线、坐标压缩

void discrete() {
    xs = a;                              //或把"所有要离散化的值"都 push_back 进 xs
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
}

int id(int x) {                          //x 离散化后的编号(1-based)
    return lower_bound(xs.begin(), xs.end(), x) - xs.begin() + 1;
}
//配套: 需要还原时原值 = xs[id - 1]
//注意: 查询不存在于 xs 中的值时, lower_bound 返回 >= x 的第一个, 视题目确定语义
