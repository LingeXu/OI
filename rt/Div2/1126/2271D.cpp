#include <bits/stdc++.h>
using namespace std;
#define int long long
int t, n, m, k;
vector< pair<int, int> > pos;
vector<int> pref_sum;
int check(int x) {
    int l = x, r = x + m - 1;
    auto it1 = lower_bound(pos.begin(), pos.end(), make_pair(l, l)), it2 = prev(lower_bound(pos.begin(), pos.end(), make_pair(r, r))), it3 = next(it2);
    return pref_sum[it2 - pos.begin()] - pref_sum[it1 - pos.begin() - 1] - max(0LL, it2->second - r) + ((it3 != pos.end() && r == it3->first) ? 1 : 0);
}
void solve() {
    pos.clear();
    pref_sum.clear();
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        pos.push_back(make_pair(l, r));
        if(i == 0)  pref_sum.push_back(r - l + 1);
        else    pref_sum.push_back(pref_sum[i - 1] + r - l + 1);
    }
    if(k == 0) {
        cout << 1e18 - k + 1 << '\n';
        return;
    }
    for(int i = 0; i < n; i++) {
        int l, r;
        if(i == 0) {
            l = 1;
            r = pos[i].first;
        }
        else {
            l = pos[i - 1].second;
            r = pos[i].first;
        }
        if(check(l) == k) {
            cout << l << '\n';
            return;
        }
        if(check(r) == k) {
            cout << r << '\n';
            return;
        }
        if(!(check(l) < k && check(r) > k))  continue;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(check(mid) > k) r = mid - 1;
            else if(check(mid) < k)   l = mid + 1;
            else {
                cout << mid << '\n';
                return;
            }
        }
    }
    cout << -1 << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--)  solve();
    return 0;
}