#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int t;
void solve() {
    int p;
    cin >> p;
    if(p == 2)  cout << 12 << ' ' << 1 << ' ' << 71 << '\n';
    else if(p == 3)    cout << 4 << ' ' << 2 << ' '<< 13 << '\n';
    else if(p > 1000000)    cout << 1000000 << ' ' << 1000000 << ' ' << 1LL * 1000000 * 1000000 - 1LL * p << '\n';
    else    cout << p - 1 << ' ' << p - 1 << ' ' << 1LL * (p - 1) * (p - 1) - 1LL * p << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0); 
    cin >> t;
    while(t--) 
        solve();
    return 0;
}