#include <bits/stdc++.h>
using namespace std;
int t, n, m;
void solve() {
    cin >> n >> m;
    int pre1, pre2, sum1 = 0, sum2 = 0;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(i != 0)
            sum1 += (pre1 - x + 1);
        if(i == n - 1)  sum1 += x;
        pre1 = x;
    }
    for(int i = 0; i < m; i++) {
        int x;
        cin >> x;
        if(i != 0)
            sum2 += (pre2 - x + 1);
        if(i == m - 1)  sum2 += x;
        pre2 = x;
    }
    if(sum1 >= sum2)    cout << 1 << '\n';
    else    cout << 2 << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--)  solve();
    return 0;
}