#include <bits/stdc++.h>
using namespace std;
int n, k;
void solve() {
    cin >> n >> k;
    unordered_map<int, int> mp;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        mp[x]++;
    }
    int cur = 0;
    bool ok = false;
    while(!ok) {
        if(mp[cur] <= 2 * (k - 1)) {
            cout << "NO\n";
            return;
        }
        if(mp[cur] == 2 * k - 1) {
            cout << "YES\n";
            return;
        }
        cur++;
    }
}
int main() {
    int t;
    cin >> t;
    while(t--)  solve();
    return 0;
}