#include <bits/stdc++.h>
using namespace std;
int n;
void solve() {
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int cur = 0;
    for(int i = n - 1; i >= 0; i--)
        cur = 2 * a[i] - cur;
    cout << cur / 2 << '\n';
}
int main() {
    int t;
    cin >> t;
    while(t--)  solve();
    return 0;
}