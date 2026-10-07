#include <bits/stdc++.h>
using namespace std;
#define int long long

// GCD Treasury
// 核心结论：最终 x = gcd(初始x, 已选堆集合 S)，与选择顺序无关；选中的堆必然拿光。
//  上界：任意可行方案最终 g >= 2，取 g 的一个质因子 p，
//        则答案 = Σ_{S} a_i <= Σ_{g|a_i} a_i <= Σ_{p|a_i} a_i；
//  可达：直接拿光所有 p | a_i 的堆一定可行（每步当前 x 都是 p 的倍数，gcd >= p）。
// 所以 ans = max_{p 为 x 的质因子} Σ_{p | a_i} a_i。复杂度 O(n*ω(x))。
void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++)  cin >> a[i];

    vector<int> ps;                          // x 的质因子（<= 6 个）
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            ps.push_back(i);
            while (x % i == 0)  x /= i;
        }
    }
    if (x > 1)  ps.push_back(x);

    int ans = 0;
    for (int p : ps) {
        int s = 0;
        for (int v : a)
            if (v % p == 0)  s += v;
        ans = max(ans, s);
    }
    cout << ans << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)  solve();
    return 0;
}
