#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k, x, y;
    cin >> n >> m >> k >> x >> y;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < m; i++)
        cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<int> presum_a(n);
    vector< pair<int, int> > presum_b(m);
    for(int i = 0; i < n; i++) {
        if(i == 0)  presum_a[i] = a[i];
        else    presum_a[i] = presum_a[i - 1] + a[i];
    }
    for(int i = 0; i < m; i++) {
        int cnt = (b[i] - 1) / k + 1;

        //cout << "cnt = " << cnt << '\n';

        if(i == 0)  presum_b[i] = make_pair(cnt, cnt * k - b[i]);
        else    presum_b[i] = make_pair(presum_b[i - 1].first + cnt, presum_b[i - 1].second + cnt * k - b[i]);
    }
    auto it = upper_bound(presum_a.begin(), presum_a.end(), x + y * k);
    int ans = it - presum_a.begin();

    //cout << "ans = " << ans << '\n';

    for(int i = 0; i < m; i++) {
        int cur = 0;
        if(presum_b[i].first > y)  break;
        int remain = x + (y - presum_b[i].first) * k + presum_b[i].second;

        //cout << "remain = " << remain << '\n';

        auto it1 = upper_bound(presum_a.begin(), presum_a.end(), remain);
        cur = it1 - presum_a.begin() + i + 1;
        ans = max(ans, cur);
    }
    cout << ans;
    return 0;
}