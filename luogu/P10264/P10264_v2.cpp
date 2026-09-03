#include <bits/stdc++.h>
#define N 15010
#define LOG 16
using namespace std;
int t, n, q;
int st[N][LOG];
void solve() {
    cin >> n;
    vector<int> a(n + 1);
    map<int, vector<int> > mp;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        mp[a[i]].push_back(i);
    }
    memset(st, 0x3f, sizeof(st));
    for(int i = 1; i <= n; i++) {
        auto it = upper_bound(mp[a[i]].begin(), mp[a[i]].end(), i);
        if(it != mp[a[i]].end())
            st[i][0] = *it;
        else    st[i][0] = 0x3f3f3f3f;
    }
    for(int i = 1; i < LOG; i++) {
        for(int j = 1; j <= n; j++) {
            if(st[j][i - 1] != 0x3f3f3f3f)
                st[j][i] = st[st[j][i - 1] + 1][i - 1];
            else    st[j][i] = 0x3f3f3f3f;
        }
    }
    cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;
        int ans = 0;
        for(int i = l; i <= r;) {
            if(st[i][0] == 0x3f3f3f3f || st[i][0] > r) {
                ans++;
                i++;
                continue;
            }
            for(int j = LOG - 1; j >= 0; j--) {
                if(st[i][j] != 0x3f3f3f3f && st[i][j] <= r) {
                    i = st[i][j] + 1;
                    if(i == r + 1) 
                        break;
                    continue;
                }
            }
        }
        cout << ans << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while(t--)  solve();
    return 0;
}