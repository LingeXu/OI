#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    string a;
    cin >> a;
    vector<int> pre(n), suf(n);
    for(int i = 0; i < n; i++) {
        if(i == 0)  pre[i] = 1;
        else    pre[i] = pre[i - 1] + (a[i] != a[i - 1]);
    }
    for(int i = n - 1; i >= 0; i--) {
        if(i == n - 1)  suf[i] = 1;
        else    suf[i] = suf[i + 1] + (a[i] != a[i + 1]);
    }
    int ans = pre[n - 1];
    for(int i = 0; i < n - 1; i++)
        ans = max(ans, pre[i] + suf[i + 1] - (a[0] == a[n - 1]));
    cout << ans << '\n';
}
int main() {
    int t;
    cin >> t;
    while(t--)  solve();
    return 0;
}