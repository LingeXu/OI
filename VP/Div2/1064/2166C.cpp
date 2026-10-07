#include <bits/stdc++.h>
using namespace std;
#define int long long
int t, n;
struct ar {
    int pre, nx, val;
};
void solve() {
    cin >> n;
    vector<int> a(n);
    priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        pq.push(make_pair(a[i], i));
    }
    vector<ar> b(n);
    for(int i = 0; i < n; i++) 
        b[i].val = a[i];
    for(int i = 0; i < n; i++) {
        if(i == n - 1)  b[i].nx = 0;
        else    b[i].nx = i + 1;
    }
    for(int i = 0; i < n; i++) {
        if(i == 0)  b[i].pre = n - 1;
        else    b[i].pre = i - 1;
    }
    int ans = 0;
    while((int)pq.size() > 1) {
        auto [val, idx] = pq.top();

        //cout << "idx = " << idx << '\n';

        pq.pop();
        int pre_val = b[b[idx].pre].val, nx_val = b[b[idx].nx].val;

        //cout << "pre = " << b[idx].pre << ", " << "nx = " << b[idx].nx << '\n';
        //cout << "pre_val = " << pre_val << ", " << "nx_val = " << nx_val << '\n';

        ans += min(pre_val, nx_val);
        b[b[idx].pre].nx = b[idx].nx;
        b[b[idx].nx].pre = b[idx].pre;

        //cout << "ans = " << ans << '\n';

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