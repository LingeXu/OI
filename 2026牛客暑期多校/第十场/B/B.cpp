// 2026牛客暑期多校第十场 B 老虎机
// n 台老虎机，奖金独立均匀 U[0,m]，每步选当前最大者领取后重掷，求 k 次总奖金期望。
//
// 关键：对阈值 x∈[0,1]，统计"奖金 > mx"的台数 j。
// 选中的是最大值机器，若 j>=1 则其必 >x（丢弃），新值 >x 概率 1-x（B~Bernoulli(1-x)），
// 其余机器保持不变，因此计数过程是马尔可夫链：
//   j=0  -> B
//   j>=1 -> j-1+B
// 转移：
//   p'(0) = x(p(0)+p(1))
//   p'(1) = (1-x)(p(0)+p(1)) + x*p(2)   （n>=2 时含末项）
//   p'(j) = (1-x)p(j) + x*p(j+1), 2<=j<=n-1
//   p'(n) = (1-x)p(n)
// 初始 p_0(j) = C(n,j)(1-x)^j x^(n-j) = 伯恩斯坦基 B_{n-j,n}(x)。
//
// 用伯恩斯坦基表示多项式（系数全非负，无抵消误差）：
//   x*B_{i,d}     = (i+1)/(d+1) * B_{i+1,d+1}
//   (1-x)*B_{i,d} = (d-i+1)/(d+1) * B_{i,d+1}
// E[V_{t+1}] = m * ∫(1 - p_t(0,x))dx = m * (1 - Σ_i c[0][i]/(d+1))。
// 复杂度 O(k*n*(n+k))。
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    long long m;
    cin >> n >> m >> k;

    int D = n + k;  // 多项式最大次数
    // c[j][i]：当前次数 d 下 B_{i,d} 的系数
    vector<vector<double> > c(n + 1, vector<double>(D + 2, 0.0));
    vector<vector<double> > nc(n + 1, vector<double>(D + 2, 0.0));

    // 初始：p_0(j) = B_{n-j,n}(x)
    for (int j = 0; j <= n; ++j) c[j][n - j] = 1.0;

    int d = n;
    double ans = m * (1.0 - 1.0 / (n + 1));  // E[V_1] = m * n/(n+1)

    for (int t = 1; t <= k - 1; ++t) {
        int d1 = d + 1;
        for (int j = 0; j <= n; ++j)
            fill(nc[j].begin(), nc[j].begin() + d1 + 1, 0.0);

        // j = 0
        for (int i = 1; i <= d1; ++i)
            nc[0][i] = (double)i / d1 * (c[0][i - 1] + c[1][i - 1]);
        // j = 1
        for (int i = 0; i <= d1; ++i) {
            double v = 0.0;
            if (i <= d) v += (double)(d - i + 1) / d1 * (c[0][i] + c[1][i]);
            if (i >= 1 && n >= 2) v += (double)i / d1 * c[2][i - 1];
            nc[1][i] = v;
        }
        // j = 2 .. n-1
        for (int j = 2; j <= n - 1; ++j)
            for (int i = 0; i <= d1; ++i) {
                double v = 0.0;
                if (i <= d) v += (double)(d - i + 1) / d1 * c[j][i];
                if (i >= 1) v += (double)i / d1 * c[j + 1][i - 1];
                nc[j][i] = v;
            }
        // j = n
        if (n >= 2)
            for (int i = 0; i <= d; ++i)
                nc[n][i] = (double)(d - i + 1) / d1 * c[n][i];

        c.swap(nc);
        d = d1;

        double mass0 = 0.0;
        for (int i = 0; i <= d; ++i) mass0 += c[0][i];
        ans += m * (1.0 - mass0 / (d + 1));
    }

    cout << fixed << setprecision(12) << ans << '\n';
    return 0;
}
