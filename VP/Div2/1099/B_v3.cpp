#include <bits/stdc++.h>
using namespace std;
int t, n;
void solve() {
    cin >> n;
    vector<int> a(n);
    int k = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(i != 0)
            k = max(k, max(0, a[i - 1] - a[i]));
    }

    //cout << "k = " << k << '\n';

    for(int i = 0; i < n - 1; i++) {
        if(a[i] - a[i + 1] > k) {
            cout << "NO\n";
            return;
        }
        else if(a[i] - a[i + 1] > 0 && a[i] - a[i + 1] <= k)
            a[i + 1] += k;
    }
    cout << "YES\n";
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while(t--)  solve();
    return 0;
}