#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    i64 n;
    cin >> n;
    i64 ans = 0;
    for (i64 b = 1; b * b <= n; b++) {
        i64 P = b * (b + 1);          
        i64 full = n / P * b;         
        i64 rem = n % P;              
        i64 partial = max(0LL, min(b, rem - b * b + 1));
        ans += full + partial;
    }
    cout << ans << "\n";
    return 0;
}
