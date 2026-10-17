//数组需有序, 返回下标; 自定义比较见 lambda自定义比较.cpp
lower_bound(a, a + n, x) - a;       //第一个 >= x 的位置
upper_bound(a, a + n, x) - a;       //第一个 >  x 的位置
binary_search(a, a + n, x);         //是否存在, 返回 bool
//vector用法: lower_bound(v.begin(), v.end(), x) - v.begin();