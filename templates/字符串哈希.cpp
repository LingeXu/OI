//字符串哈希: 判断子串相等 / 二分求 LCP / 比较字典序, 双哈希防冲突
//需预定义: ll h1[N], h2[N], p1[N], p2[N];   (h*[i] = s[1..i] 的哈希, 前缀哈希)
//入口: init(s);  s 下标从 1 开始(可在前面加个空格或 s = " " + s)
const int BASE = 131;
const int MOD1 = 1000000007, MOD2 = 1000000009;

void init(const string& s) {
    int n = s.size() - 1;                //s 有效下标 1..n
    p1[0] = p2[0] = 1;
    for(int i = 1; i <= n; i++) {
        p1[i] = p1[i - 1] * BASE % MOD1;
        p2[i] = p2[i - 1] * BASE % MOD2;
        h1[i] = (h1[i - 1] * BASE + s[i]) % MOD1;
        h2[i] = (h2[i - 1] * BASE + s[i]) % MOD2;
    }
}

ll get_h1(int l, int r) {                //子串 [l, r] 在 mod1 下的哈希
    return ((h1[r] - h1[l - 1] * p1[r - l + 1]) % MOD1 + MOD1) % MOD1;
}
ll get_h2(int l, int r) {
    return ((h2[r] - h2[l - 1] * p2[r - l + 1]) % MOD2 + MOD2) % MOD2;
}
bool equal(int l1, int r1, int l2, int r2) {    //O(1) 判断两子串相等
    return get_h1(l1, r1) == get_h1(l2, r2) && get_h2(l1, r1) == get_h2(l2, r2);
}

//二分求 LCP: s[a..] 与 s[b..] 的最长公共前缀长度, O(log n)
int lcp(int a, int b, int n) {
    int l = 0, r = min(n - a + 1, n - b + 1), ans = 0;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(equal(a, a + mid - 1, b, b + mid - 1)) {
            ans = mid;
            l = mid + 1;
        }
        else    r = mid - 1;
    }
    return ans;
}

//配套:
//1. 比较两个子串字典序: 先 LCP, 若 LCP 覆盖其中一方则该子串小; 否则比 LCP 后一个字符
//2. 判断回文子串: 正反串各建一个哈希, [l, r] 回文 <=> 正串 hash(l,r) == 反串 hash(n-r+1, n-l+1)
//3. 匹配: 模式串长度 m, 枚举文本每个起点 O(1) 比较子串哈希
