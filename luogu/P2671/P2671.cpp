#include <bits/stdc++.h>
#define N 100010
const int MOD = 10007;
typedef long long ll;
using namespace std;
int n, m;
ll ans = 0;
struct grid {
    int val, color;
}g[N];
int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> g[i].val;
    for(int i = 1; i <= n; i++)
        cin >> g[i].color;
    for(int i = 2; i < n; i += 2) {
        for(int j = 1; j <= n - i; j++) {
            int Left = j;
            int Right = Left + i;
            if(g[Left].color == g[Right].color) 
                ans += 1LL * (Left + Right) * (g[Left].val+ g[Right].val) % MOD; 
        }
    }
    cout << ans % MOD;
    return 0;
}