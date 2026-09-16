#include <bits/stdc++.h>
using namespace std;
int t, n;
void solve() {
    cin >> n;
    vector<int> a(n + 1);
    vector<bool> has(n, true);
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++) {
        for(int j = a[i] * i; j < (a[i] + 1) * i; j++) {
            if(j >= n)   break;
            has[j] = false;
        }
    }
    int cnt = 0;
    for(int i = 0; i < n; i++)
        if(has[i])
            cnt++;
    cout << cnt << '\n';
    for(int i = 0; i < n; i++)
        if(has[i])
            cout << i << ' ';
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--)  solve();
    return 0;
}