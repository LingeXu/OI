#include <bits/stdc++.h>
using namespace std;
int t, n;
bool cmp(int x, int y) {
    return x > y;
}
void solve() {
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end(), cmp);
    if(n == 1) {
        cout << a[0] << '\n';
        return;
    }
    for(int i = 0; i < n - 1; i++) {
        if(a[i] == a[i + 1]) {
            cout << -1 << '\n';
            return;
        }
    }
    for(int i = 0; i < n; i++) 
        cout << a[i] << ' ';
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--)  solve();
    return 0;
}