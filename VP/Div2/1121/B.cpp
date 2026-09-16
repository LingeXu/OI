#include <bits/stdc++.h>
#define int long long
using namespace std;
int t, n, m;
void solve() {
    cin >> n >> m;
    vector<int> a(n + 1);
    int mx = -LLONG_MAX;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    if(m == 1) {
        cout << mx << '\n';
        return;
    }
    int start = 0;
    vector<int> presum(n + 1);
    priority_queue< int, vector<int>, less<int> > pq;
    for(int i = 1; i <= m - 1; i++) {
        pq.push(a[i]);
        start += a[i];

        //cout << "pq.top() = " << pq.top() << '\n';

    }
    presum[m - 1] = start;
    for(int i = m; i <= n; i++) {
        if(a[i] >= pq.top()) {
            presum[i] = presum[i - 1];
            continue;
        }
        presum[i] = presum[i - 1] - pq.top() + a[i];
        pq.pop();
        pq.push(a[i]);
    }
    int ans = -LLONG_MAX;
    for(int i = m; i <= n; i++) {
        ans = max(ans, -presum[i - 1] + m * a[i]);
    }
    cout << ans << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--)  solve();
    return 0;
}