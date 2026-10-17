//Z函数: z[i] = s[0..] 与 s[i..] 的最长公共前缀长度, z[0] = 0
//O(n), 用于字符串匹配、求周期/border 相关
//需预定义: int z[N];

void get_z(const string& s) {
    int n = s.size();
    int l = 0, r = 0;                    //维护最右匹配段 [l, r] = s[0..r-l]
    for(int i = 1; i < n; i++) {
        z[i] = (i <= r ? min(r - i + 1, z[i - l]) : 0);
        while(i + z[i] < n && s[z[i]] == s[i + z[i]])    z[i]++;
        if(i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
}

//匹配: 构造 t = p + '#' + s, 求 t 的 z 数组
//若 z[|p| + 1 + i] == |p|, 则 p 在 s 的 i 处出现
//周期: 若 i + z[i] == n, 则 n - i 是 s 的一个周期
