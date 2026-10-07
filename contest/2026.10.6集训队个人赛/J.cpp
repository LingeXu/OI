#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n + 5);
    unordered_map<int, int> cnt;
    for(int i = 1; i <= n; i++) {
        cin >> a[i + 2];
        cnt[a[i + 2]]++;
    }
    a[1] = a[n + 1];
    a[2] = a[n + 2];
    a[n + 3] = a[3];
    a[n + 4] = a[4];
    vector<int> ans(100005, LLONG_MAX);
    for(int i = 3; i <= n + 2; i++) {
        if(a[i] >= a[i - 1] && a[i] >= a[i - 2]) {
            ans[a[i]] = min(ans[a[i]], n - cnt[a[i]]);
            continue;
        }
        if(a[i] >= a[i - 1] && a[i] >= a[i + 1]) {
            ans[a[i]] = min(ans[a[i]], n - cnt[a[i]]);
            continue;
        }
        if(a[i] >= a[i + 1] && a[i] >= a[i + 2]) {
            ans[a[i]] = min(ans[a[i]], n - cnt[a[i]]);
            continue;
        }
        if(a[i] <= a[i - 1] && a[i] <= a[i - 2]) {
            ans[a[i]] = min(ans[a[i]], n - cnt[a[i]]);
            continue;
        }
        if(a[i] <= a[i - 1] && a[i] <= a[i + 1]) {
            ans[a[i]] = min(ans[a[i]], n - cnt[a[i]]);
            continue;
        }
        if(a[i] <= a[i + 1] && a[i] <= a[i + 2]) {
            ans[a[i]] = min(ans[a[i]], n - cnt[a[i]]);
            continue;
        }
        else {
            ans[a[i]] = min(ans[a[i]], n - cnt[a[i]] + 1);
            continue;
        }
    }
    for(int i = 3; i <= n + 2; i++)
        cout << ans[a[i]] << ' ';
    return 0;
}