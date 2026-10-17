#include <bits/stdc++.h>
using namespace std;
#define int long long
int t, n, m;
void solve() {
    cin >> n >> m;
    vector<int> deg(n + 1, 0);
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        deg[u]++;
        deg[v]++;
    }
    for(int i = 1; i <= n; i++) {
        if(deg[i] == 0) {
            cout << "Brain Melt\n";
            return;
        }
    }
    int cnt_1 = 0, cnt_n = 0;
    for(int i = 1; i <= n; i++) {
        if(deg[i] == 1)
            cnt_1++;
        if(deg[i] == n - 1)
            cnt_n++;
    }
    if(cnt_1 == n - 1 && cnt_n == 1) {
        cout << 2 << '\n';
        return;
    }
    if(cnt_1 == 2 && n == 2) {
        cout << 2 << '\n';
        return;
    }
    cout << "Many\n";
    return;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--)  solve();
    return 0;
}