//三分搜索: 单峰(单谷)函数求极值, O(log n)
//前提: f 在 [L, R] 上严格先减后增(下凸求最小值)或先增后减(上凸求最大值)

//整数域三分: 下凸求最小值
int l = L, r = R;
while(r - l > 2) {                       //剩 <= 3 个点时退出, 逐一比较
    int m1 = l + (r - l) / 3;
    int m2 = r - (r - l) / 3;
    if(f(m1) < f(m2))    r = m2;         //最小值在 [l, m2]
    else    l = m1;                      //最小值在 [m1, r]
}
int ans = f(l);
for(int i = l + 1; i <= r; i++)    ans = min(ans, f(i));

//浮点域三分: 迭代 100~200 次, 或 while(r - l > eps)
//double l = L, r = R;
//for(int t = 0; t < 200; t++) {
//    double m1 = l + (r - l) / 3;
//    double m2 = r - (r - l) / 3;
//    if(f(m1) < f(m2))    r = m2;
//    else    l = m1;
//}
//ans 取 l(或 (l+r)/2)
