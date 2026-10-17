//lambda自定义比较: 比较器必须满足严格弱序(用 < 或 >, 不能用 <= / >=)

//sort: 返回 true 表示 x 应排在 y 前面
sort(a.begin(), a.end(), [](const T& x, const T& y) {
    return x.w < y.w;                //按w升序
});
sort(a.begin(), a.end(), [](const T& x, const T& y) {
    return tie(x.w, x.v) < tie(y.w, y.v);    //多关键字: 先w后v升序
});

//lower_bound: 找第一个满足 comp(元素, 值) 为假的位置
//前提: 数组已按"被比较的键"有序, 比较器形如 comp(元素, 值)
//找第一个 w >= v 的下标:
lower_bound(a.begin(), a.end(), v, [](const T& x, int val) {
    return x.w < val;
}) - a.begin();

//upper_bound: 找第一个 comp(值, 元素) 为真的位置, 注意参数顺序是 (值, 元素)
//找第一个 w > v 的下标:
upper_bound(a.begin(), a.end(), v, [](int val, const T& x) {
    return val < x.w;
}) - a.begin();

//对pair的second二分: pair已按first有序且second单调递增时可用(如区间左端点有序且互不相交)
lower_bound(a.begin(), a.end(), v, [](const pair<int, int>& p, int val) {
    return p.second < val;
}) - a.begin();

//priority_queue: 与sort相反, > 得到小根堆; C++17需构造时传入比较器
auto cmp = [](const T& x, const T& y) {
    return x.w > y.w;
};
priority_queue<T, vector<T>, decltype(cmp)> pq(cmp);

//set/map: 比较器写在模板参数里, 构造时同样要传实例
auto cmp2 = [](int x, int y) {
    return x > y;                    //降序
};
set<int, decltype(cmp2)> st(cmp2);
