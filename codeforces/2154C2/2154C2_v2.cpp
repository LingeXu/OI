#include <bits/stdc++.h>
#define int long long
using namespace std;

// CF2154C2 No Cost Too Great (Hard Version) 修正版
// WA 原因：全奇数时，v1 只把 b == mn1 的元素当作"锚点质数 p 的搭档"，
// 漏掉了 b 更大但 k 更小的元素（如 a[i] % p == p-1，只需 +1 步）。
// 修正：答案 = min(p=2 基准, 每个元素 +1 后撞上其他元素质因子的花费,
//                 唯一最小 b 元素对每个锚点质数 p 的 b*(p - a%p))
// 复杂度 O(sum n + maxA)，cnt 用 touched 列表复位（不整段清空）
const int MAXV = 400000; // a[i] + k <= 2e5 + 2e5
vector<int> spf(MAXV + 1, 0);
vector<int> cnt(MAXV + 1, 0);

void sieve() {
    for (int i = 2; i <= MAXV; i++) {
        if (!spf[i]) {
            spf[i] = i;
            if (i * i > MAXV) continue;
            for (int j = i * i; j <= MAXV; j += i)
                if (!spf[j]) spf[j] = i;
        }
    }
}

int t, n;
void solve() {
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    // 统计每个质数被多少个元素整除；>=2 则已有 gcd > 1
    vector<int> touched;
    bool zero = false;
    for (int i = 0; i < n && !zero; i++) {
        int x = a[i];
        while (x > 1) {
            int p = spf[x];
            if (++cnt[p] == 2) { zero = true; break; }
            touched.push_back(p);
            while (x % p == 0) x /= p;
        }
    }
    if (zero) {
        cout << 0 << '\n';
        for (int p : touched) cnt[p] = 0;
        return;
    }

    // p = 2 基准：偶数元素花费 0，奇数元素花费 b[i]，取两个最小
    int c1 = LLONG_MAX, c2 = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        int c = (a[i] % 2 == 0) ? 0 : b[i];
        if (c <= c1) { c2 = c1; c1 = c; }
        else if (c < c2) c2 = c;
    }
    int ans = c1 + c2;

    if (!touched.empty()) {
        // k = 1：所有元素 +1 后是否撞上其他元素的质因子
        // （p | a[i]+1 时必有 p ∤ a[i]，锚点一定是其他元素）
        for (int i = 0; i < n; i++) {
            int x = a[i] + 1;
            while (x > 1) {
                int p = spf[x];
                if (cnt[p] >= 1) { ans = min(ans, b[i]); break; }
                while (x % p == 0) x /= p;
            }
        }
        // k > 1：b[i] >= mn2 的元素不可能更优（ans <= mn1+mn2 <= 2*mn2），
        // 只有唯一最小 b 元素可能用得上，直接枚举锚点质数
        int mnid = -1, mncnt = 0;
        int mn1 = LLONG_MAX;
        for (int i = 0; i < n; i++)
            if (b[i] < mn1) { mn1 = b[i]; mnid = i; mncnt = 1; }
            else if (b[i] == mn1) mncnt++;
        if (mncnt == 1) {
            for (int p : touched) {
                if (a[mnid] % p == 0) continue; // 锚点是自身，无效
                ans = min(ans, b[mnid] * (p - a[mnid] % p));
            }
        }
    }
    cout << ans << '\n';
    for (int p : touched) cnt[p] = 0;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve();
    cin >> t;
    while (t--) solve();
    return 0;
}
