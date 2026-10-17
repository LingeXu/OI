// CCPC2026 网络热身赛2 L — 花窗玻璃 / 逆序数构造
// 题意:把 1..n 分成 b 个连续块(大小 s_i 为正整数,和为 n),
//       每块内部严格降序,按块拼接成排列 p。
//       求一组合法的 s 与 p,使 inv(p)=k,否则 IMPOSSIBLE。
// 关键:inv(p) = Σ C(s_i,2)。即找 e_i=s_i-1>=0,Σe=E=n-b,Σ T(e_i)=k (T(x)=x(x+1)/2)。
// 算法:递归贪心。每层取最大的 t(本块 e 值)使得子问题边界可行,再递归验证。
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll T(ll x) { return x * (x + 1) / 2; }

// 最小可达 k:E 个硬币放进 b 个盒子,尽量均匀
ll kmin(ll E, ll b) {
    ll q = E / b, r = E % b;
    return r * T(q + 1) + (b - r) * T(q);
}

vector<ll> ans;  // 各块的 e 值(倒序存储,最后 reverse)

bool solve(ll E, ll b, ll k) {
    if (b == 0) return E == 0 && k == 0;
    if (b == 1) {
        if (T(E) == k) { ans.push_back(E); return true; }
        return false;
    }
    if (k < kmin(E, b) || k > T(E)) return false;
    // tmax = 最大的 t 使 T(t) <= k
    ll lo = 0, hi = E, tmax = 0;
    while (lo <= hi) {
        ll mid = (lo + hi) / 2;
        if (T(mid) <= k) { tmax = mid; lo = mid + 1; }
        else hi = mid - 1;
    }
    for (ll t = tmax; t >= 0; t--) {
        ll restE = E - t, restk = k - T(t);
        if (restk < kmin(restE, b - 1)) continue;   // 剩余部分最少也要 restk
        if (restk > T(restE)) continue;             // 剩余部分最多只有 T(restE)
        ans.push_back(t);
        if (solve(restE, b - 1, restk)) return true;
        ans.pop_back();
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, b, k;
    cin >> n >> b >> k;
    if (b > n) { cout << "IMPOSSIBLE\n"; return 0; }
    ll E = n - b;
    if (k > T(E)) { cout << "IMPOSSIBLE\n"; return 0; }
    ans.clear();
    if (!solve(E, b, k)) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    reverse(ans.begin(), ans.end());  // e_1..e_b
    vector<ll> s(b);
    for (int i = 0; i < b; i++) s[i] = ans[i] + 1;
    for (int i = 0; i < b; i++) {
        if (i) cout << ' ';
        cout << s[i];
    }
    cout << '\n';
    ll pre = 0;
    bool first = true;
    for (int i = 0; i < b; i++) {
        // 块 i 的值为 [pre+1, pre+s_i],严格降序输出
        for (ll v = pre + s[i]; v > pre; v--) {
            if (!first) cout << ' ';
            first = false;
            cout << v;
        }
        pre += s[i];
    }
    cout << '\n';
    return 0;
}
