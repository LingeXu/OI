#include <bits/stdc++.h>
#define int long long
#define MOD 998244353
using namespace std;
int n;
int quick_pow(int a, int p) {
    int res = 1;
    while(p) {
        if(p & 1) 
            res = res * a % MOD;
        a = a * a % MOD;
        p >>= 1;
    }
    return res;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    cout << ((quick_pow(4, n) - quick_pow(3, n + 1) + MOD) % MOD + 3 * quick_pow(2, n) % MOD - 1 + MOD) % MOD;
    return 0;
}