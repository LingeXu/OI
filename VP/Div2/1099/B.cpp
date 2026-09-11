#include <bits/stdc++.h>
#define int long long
using namespace std;
int t, n;
void solve() {
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    vector<bool> need(n);
    int mn;
    for(int i = n - 1; i >= 0; i--) {
        if(i == n - 1) {
            need[i] = true;
            mn = a[i];
            continue;
        }
        else {
            if(a[i] <= mn) {
                need[i] = true;
                mn = a[i];
            }
        }
    }

    int mx = 0, ans = 0;
    for(int i = 0; i < n; i++) {
        if(need[i] == false) {
            mx = max(mx, a[i]);
            continue;
        }
        else {
            if(mx - a[i] <= 0) {
                need[i] = false;
                mx = a[i];
            }
            else {
                ans = max(ans, mx - a[i]);
            }
        }
    }
    for(int i = 0; i < n; i++) {
        if(need[i] == true) {
            a[i] += ans;

        }
    }
    for(int i = 0; i < n - 1; i++) {
        if(a[i] > a[i + 1]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES" << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--)  solve();
    return 0;
}