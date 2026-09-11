#include <bits/stdc++.h>
using namespace std;
int t, n, m;
void solve() {
    cin >> n >> m;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) 
        cin >> a[i];
    int mx = 0;
    for(int i = 1; i <= n;) {
        int cur = 0;
        int j = i;
        while(j <= n && a[j] == a[i]) {
            cur++;
            j++;
        }
        mx = max(mx, cur);
        i = j;
    }
    if(mx >= m) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--)  solve();
    return 0;
}