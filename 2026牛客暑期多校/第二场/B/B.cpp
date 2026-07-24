#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct LinearBasis {
    ll b[65];  // b[i] 表示第 i 位的基
    int cnt;
    
    LinearBasis() {
        memset(b, 0, sizeof(b));
        cnt = 0;
    }
    
    void insert(ll x) {
        for (int i = 60; i >= 0; i--) {
            if (!(x >> i & 1)) continue;
            if (!b[i]) {
                b[i] = x;
                cnt++;
                return;
            }
            x ^= b[i];
        }
    }
    
    // 求最大异或值
    ll queryMax() {
        ll res = 0;
        for (int i = 60; i >= 0; i--) {
            if ((res ^ b[i]) > res) res ^= b[i];
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        ll total = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            total ^= a[i];
        }
        
        // mask: total 为 0 的位是 1
        // 由于 a[i] < 2^30，我们只需要 30 位
        ll mask = ((1LL << 30) - 1) ^ total;
        
        LinearBasis lb;
        for (ll x : a) {
            lb.insert(x & mask);
        }
        
        ll best = lb.queryMax();
        cout << total + 2 * best << "\n";
    }
    return 0;
}
