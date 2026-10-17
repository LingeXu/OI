//求定长窗口 [x, x+m-1] 覆盖的点数; 区间按 l 排序且互不相交(则 r 也单调递增, 这是按 second 二分的前提)
//需预定义: vector<pair<int,int>> inf(n);  vector<int> pref(n + 1);
//         pref[i + 1] = pref[i] + inf[i].second - inf[i].first + 1;
//口诀: 左端找 r, 右端找 l, 中间全加两头修剪, 一个if管越界
int f(int x) {
    int e = x + m - 1;
    //第一个右端够到 x 的区间(不存在时 lower_bound 返回 end, pos1 = n)
    int pos1 = lower_bound(inf.begin(), inf.end(), x,
        [](const pair<int,int>& p, int v) { return p.second < v; }) - inf.begin();
    //最后一个左端不超过 e 的区间(不存在时 upper_bound 返回 begin, pos2 = -1)
    int pos2 = upper_bound(inf.begin(), inf.end(), make_pair(e, LLONG_MAX)) - inf.begin() - 1;
    if(pos1 > pos2)    return 0;    //哨兵 n / -1 自动落入此分支, 且 return 在解引用之前, 不会越界
    return pref[pos2 + 1] - pref[pos1]    //[pos1, pos2] 全部区间全长
        - max(0LL, x - inf[pos1].first)   //修剪左端: x 落在区间内部时左边露出的部分
        - max(0LL, inf[pos2].second - e); //修剪右端: e 落在区间内部时右边露出的部分
}
