#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + m - 1);
    int cur = 0, ans;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(i < m)   cur += a[i];
    }
    for(int i = n; i < n + m - 1; i++)
        a[i] = a[i - n];
    ans = cur;
    int id = 0;
    for(int i = 1; i + m - 1 < n + m - 1; i++) {
        cur = cur + a[i + m - 1] - a[i - 1];
        if(cur > ans) {
            ans = cur;
            id = i;
        }
    }
    cout << ans << '\n';
    cout << id + 1 << '\n';
}