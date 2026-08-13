#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 998244353;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<ll> a(n);
    __int128 total = 0;      // 总能量
    ll full_blocks = 0;      // 完整 x-块数量
    vector<int> deficits;    // 各符咒的缺额

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        total += a[i];
        full_blocks += a[i] / x;
        int r = a[i] % x;
        if (r > 0) {
            deficits.push_back(x - r);
        }
    }

    // x == 2：总能耗尽全部能量
    if (x == 2) {
        cout << "0\n";
        return;
    }

    sort(deficits.begin(), deficits.end());
    int x_minus_1 = x - 1;
    int x_minus_2 = x - 2;
    ll spells = 0;
    int m = deficits.size();
    int idx = 0;  // 当前处理到的缺额下标

    // 阶段1：用完整块消除缺额
    while (idx < m && full_blocks > 0) {
        int d = deficits[idx];
        ll need = d - 1;  // 完全消除此缺额需消耗的完整块数
        if (full_blocks >= need) {
            full_blocks -= need;
            spells += d;   // need 次 F--，1 次 F 不变（退款）
            idx++;         // 此缺额已消除
        } else {
            // 完整块不够，部分处理
            spells += full_blocks;
            int remaining_d = d - full_blocks;
            full_blocks = 0;
            if (remaining_d == 1) {
                spells++;      // 退款施法
                idx++;         // 缺额被消费
            }
            // 否则卡住，退出阶段1
            break;
        }
    }

    // 阶段2：缺额全消除，只剩完整块（所有符咒余数均为0）
    if (full_blocks > 0 && idx >= m) {
        ll batches = full_blocks / x_minus_2;
        spells += batches * x_minus_1;
        full_blocks %= x_minus_2;

        if (full_blocks > 0) {
            spells += full_blocks;
            int remaining_d = x_minus_1 - full_blocks;
            if (remaining_d == 1) {
                spells++;
            }
        }
    }

    // 阶段3：F=0，检查剩余缺额中是否有 1（能量恰为 x-1 的符咒）
    if (full_blocks == 0) {
        while (idx < m && deficits[idx] == 1) {
            spells++;
            idx++;
        }
    }

    // 计算答案
    __int128 remaining = total - spells * (__int128)(x_minus_1);
    cout << (ll)(remaining % MOD) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
