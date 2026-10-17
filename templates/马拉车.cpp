string init(const string& s) {
    string res = "*";               //首尾和字符间插入分隔符, 统一奇偶回文
    for(char c : s) {
        res += c;
        res += '*';
    }
    return res;
}

//返回最长回文子串长度
//d[i] = 以 i 为中心的最长回文半径(单侧匹配的字符数); L, R = 当前已知最靠右的回文区间
int manacher(const string & s) {
    int res = 0;
    string t = init(s);
    int n = t.size();
    vector<int> d(n);
    int L = -1, R = -1;
    for(int i = 0; i < n; i++) {
        //对称点 L+R-i 的回文半径 d[L+R-i] 是下界(+1 换算成半径), 且不超过右边界 R-i+1
        int k = (i > R ? 1 : min(d[L + R - i] + 1, R - i + 1));
        while(i - k >= 0 && i + k < n && t[i - k] == t[i + k])  k++;
        d[i] = --k;                 //k 多走一步, 减回来
        if(i + k > R) {
            L = i - k;
            R = i + k;
        }
        res = max(res, d[i]);
    }
    return res;
}