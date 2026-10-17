#include <bits/stdc++.h>
using namespace std;
#define int long long
int t, n, m, k;
vector< pair<int, int> > inf(200005);
vector<int> pref_sum(200005);
int f(int x) {
    int e = x + m - 1;
    int pos1 = lower_bound(inf.begin(), inf.end(), x,
        [](const pair<int,int>& p, int v) { return p.second < v; }) - inf.begin();   
    int pos2 = upper_bound(inf.begin(), inf.end(), make_pair(e, LLONG_MAX)) - inf.begin() - 1;  
    if (pos1 > pos2) return 0;
    int res = pref_sum[pos2 + 1] - pref_sum[pos1];
    res -= max(0LL, x - inf[pos1].first);  
    res -= max(0LL, inf[pos2].second - e);  
    return res;
}

void solve() {
    cin >> n >> m >> k;
    inf.resize(n); 
    pref_sum.assign(n + 1, 0);
    for(int i = 0; i < n; i++) {
        cin >> inf[i].first >> inf[i].second;
        pref_sum[i + 1] = pref_sum[i] + inf[i].second - inf[i].first + 1;
    }
    int mx = 0, mx_id = -1;
    for(int i = 0; i < n; i++) {
        int cur = f(inf[i].first);
        if(cur > mx) { 
            mx = cur;
            mx_id = i;
        }
    }

    //cout << "Test:\n";
    //cout << "mx = " << mx << ", mx_id = " << mx_id << '\n';

    if(k > mx) {
        cout << -1 << '\n';
        return;
    }
    else if(k == mx) {
        cout << inf[mx_id].first << '\n';
        return;
    }
    else {
        int l = inf[mx_id].first, r = 1e15 + 1;
        while(r - l > 1) {
            int mid = l + (r - l) / 2;
            if(f(mid) > k)    l = mid;
            else    r = mid;

            //cout << "mid = " << mid << ", f = " << f(mid) << '\n';
        }
        cout << r << '\n';
        return;
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--)  solve();
    return 0;
}