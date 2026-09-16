#include <bits/stdc++.h>
using namespace std;
int t, n;
void solve() {
    cin >> n;
    vector<int> a(n * n + 1);
    for(int i = 1; i <= n * n; i++) {
        int x;
        cin >> x;
        a[x]++;
    }
    int mx = 0;
    for(int i = 1; i <= n * n; i++)
        if(a[i] > mx)
            mx = a[i];
    if(mx > (n - 1) * n) {
        cout << "NO\n";
        return;
    }
    else {
        cout << "YES\n";
        return;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--)  solve();
    return 0;
}