#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 200020
const int MOD = 998244353;
int fa[N];
int quick_pow(int a, int p) {
    int res = 1, base = a;
    while(p) {
        if(p & 1)   res = res * base % MOD;
        p >>= 1;
        base = base * base % MOD;
    }
    return res;
}
int inv(int x) {
    return quick_pow(x, MOD - 2);
}
void init() {
    fa[0] = 1;
    for(int i = 1; i < N; i++)
        fa[i] = fa[i - 1] * i % MOD;
}
signed main() {
    int t;
    cin >> t;
    init();
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n), suffix(n + 1);
        for(int i = 0; i < n; i++) 
            cin >> a[i];
        if(n == 1) {
            cout << 0 << '\n';
            continue;
        }
        sort(a.begin(), a.end());
        for(int i = n - 1; i >= 0; i--)
            suffix[i] = (suffix[i + 1] + a[i] % MOD) % MOD;
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int w =  (suffix[i + 1] - ((n - 1 - i) * a[i] % MOD) % MOD + MOD) % MOD;
            ans = (ans + (fa[n - 1] * inv(n - 1 - i) % MOD * w) % MOD) % MOD;
        }
        cout << ans << '\n';
    }
    return 0;
}