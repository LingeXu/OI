#include <bits/stdc++.h>
#define int long long
#define N 1000001
using namespace std;
int t, n, m;
vector<int> a[N];
bool cmp(int x, int y) {
    return x > y;
}
void solve() {
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        a[i].clear();
    vector<int> v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int x;
            cin >> x;
            a[i].push_back(x);
        }
        sort(a[i].begin(), a[i].end(), cmp);
    }
    int ans = m;
    for(int i = 0; i < n; i++) {
        int cur = 0;
        int aim = v[i];
        vector<int> top(n + 1, 0);
        while(aim > 0) {
            int mx = 0;
            int idx = -1;
            for(int j = i; j < n; j++) {
                if(top[j] < (int)a[j].size() && a[j][top[j]] > mx) {
                    mx = a[j][top[j]];
                    idx = j;
                }
            }
            top[idx]++;
            cur++;
            if(cur >= ans)  break;
            aim -= mx;

            //cout << "aim = " << aim << '\n';
        }
        ans = min(ans, cur);
    }
    cout << ans << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while(t--)  solve();
    return 0;
}