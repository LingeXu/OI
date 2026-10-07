#include <bits/stdc++.h>
using namespace std;
#define int long long
int t, n;
bool cmp(pair<int, int>& x, pair<int, int>& y) {
    return x.first > y.first;
}
void solve() {
    cin >> n;
    vector<int> a(n), b(n), pref_min(n), pref_max(n), suff_min(n), suff_max(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(i == 0)  pref_min[i] = pref_max[i] = a[i];
        else {
            pref_min[i] = min(pref_min[i - 1], a[i]);
            pref_max[i] = max(pref_max[i - 1], a[i]);
        }
    }
    for(int i = 0; i < n; i++) 
        cin >> b[i];
    for(int i = n - 1; i >= 0; i--) {
        if(i == n - 1)  suff_min[i] = suff_max[i] = b[i];
        else {
            suff_min[i] = min(suff_min[i + 1], b[i]);
            suff_max[i] = max(suff_max[i + 1], b[i]);
        }
    }

    /*cout << "Test:\n";
    for(int i = 0; i < n; i++) {
        cout << "pref_min = " << pref_min[i] << '\n';
        cout << "pref_max = " << pref_max[i] << '\n';
        cout << "suff_min = " << suff_min[i] << '\n';
        cout << "suff_max = " << suff_max[i] << '\n';
    }*/
    
    vector< pair<int, int> > record;
    for(int i = 0; i < n; i++) {
        int l = min(pref_min[i], suff_min[i]);
        int r = max(pref_max[i], suff_max[i]);
        record.push_back(make_pair(l, r));
    }
    sort(record.begin(), record.end(), cmp);
    int ans = 0;
    int pre_l = 2 * n, pre_r = 2 * n + 1;
    for(auto &[l, r] : record) {

        /*cout << "l = " << l << '\n';
        cout << "r = " << r << '\n';*/

        if(r >= pre_r)  continue;
        ans += l * (pre_r - r);

        //cout << "ans = " << ans << '\n';
        
        pre_l = l;
        pre_r = r;
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