#include <bits/stdc++.h>
using namespace std;
#define int long long
int t, n, m, k;
string s;
void solve() {
    cin >> n >> m >> k;
    vector<int> a(n), b(m), alive(n, 1);
    for(int i = 0; i < n; i++) 
        cin >> a[i];
    for(int i = 0; i < m; i++) 
        cin >> b[i];
    sort(b.begin(), b.end());
    cin >> s;
    vector< vector<int> > die(2 * k + 1);
    for(int i = 0; i < n; i++) {
        auto it = upper_bound(b.begin(), b.end(), a[i]);
        if(it == b.end()) {
            int mov = b[m - 1] - a[i];
            if(mov < -k || mov > k)
                continue;
            die[mov + k].push_back(i);
            continue;
        }
        if(it == b.begin()) {
            int mov = b[0] - a[i];
            if(mov < -k || mov > k)
                continue;
            die[mov + k].push_back(i);
            continue;
        }
        int mov1 = *prev(it) - a[i], mov2 = *it - a[i];
        if(mov1 >= -k && mov1 <= k)
            die[mov1 + k].push_back(i);
        if(mov2 >= -k && mov2 <= k)
            die[mov2 + k].push_back(i);
    }
    int cnt = n, cur = 0;
    for(char c : s) {
        cur += (c == 'L' ? -1 : 1);
        for(int idx : die[cur + k]) {
            if(alive[idx] == 1) {
                alive[idx] = 0;
                cnt--;
            }
        }
        die[cur + k].clear();
        cout << cnt << ' ';
    }
    cout << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--)  solve();
    return 0;
}