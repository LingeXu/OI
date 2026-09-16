#include <bits/stdc++.h>
#define int long long 
using namespace std;
int t, n, q;
int mex(vector<int>& a, int k, vector<int>& mark, int ti) {
    for(int i = 0; i < n; i++) {
        int can1 = a[i], can2 = k - a[i];
        int mx = max(can1, can2);
        int mn = min(can1, can2);
        if(mn > n)
            continue;
        if(mn < 0) {
            if(mx >= 0 && mx <= n)  
                mark[mx] = ti;
        }
        else {
            if(mx > n) {
                mark[mn] = ti;
                continue;
            }
            if(mark[mn] == ti)  mark[mx] = ti;
            else    mark[mn] = ti;
        }
    }
    int res = 0;
    while(mark[res] == ti)
        res++;
    return res;
}
void solve() {
    cin >> n;
    int ti = 0;
    vector<int> a(n), mark(n + 1);
    for(int i = 0; i < n; i++) 
        cin >> a[i];
    int origin_mex = mex(a, -1, mark, ++ti);

    //cout << "origin_mex = " << origin_mex << '\n';

    vector< pair<int, int> > record;
    for(int i = 0; i < n; i++)
        record.push_back(make_pair(a[i] + origin_mex, mex(a, a[i] + origin_mex, mark, ++ti)));
    sort(record.begin(), record.end());
    cin >> q;
    vector<int> query(q);
    for(int i = 0; i < q; i++)
        cin >> query[i];
    sort(query.begin(), query.end());
    int res = 0;
    for(int i = 0; i < q; ) {
        int j = i;
        while(j < q && query[j] == query[i])    j++;
        if((j - i) % 2 == 0) {
            i = j;
            continue;
        }
        auto it = lower_bound(record.begin(), record.end(), make_pair(query[i], -1));
        if(it != record.end() && it->first == query[i])
            res ^= it->second;
        else    res ^= origin_mex;
        i = j;
    }
    cout << res << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--)  solve();
    return 0;
}