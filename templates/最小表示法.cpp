//最小表示法: 循环同构串中字典序最小的表示, O(n)
//返回最小表示起始下标(0-based), 例: "bcab" 的最小表示是 "abbc", 返回 2
int min_representation(const string& s) {
    int n = s.size();
    int i = 0, j = 1, k = 0;             //i, j 两个候选起点, k 为当前比较长度
    while(i < n && j < n && k < n) {
        char a = s[(i + k) % n], b = s[(j + k) % n];
        if(a == b)    k++;
        else {
            if(a > b)    i += k + 1;      //i 开头的串在 k 处更大, i 及其后 k 个都不可能是答案
            else    j += k + 1;
            if(i == j)    j++;
            k = 0;
        }
    }
    return min(i, j);
}
//判断两个循环串是否同构: 各取最小表示比较是否相等
//最大表示: 把 a > b 改为 a < b
