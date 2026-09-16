#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 998244353;
int n;
multiset<int> s;
int dfs(int pos, int mx, int mn) {
    int ans = 0;
    if(mx < mn)
        swap(mx, mn);
    if(pos == n + 1) return 1;
    auto it1 = s.find(mx);
    auto it2 = s.find(mn);
    if(*s.begin() < mn)
        return 0;
    if(mx == mn) {
        s.erase(it1);
        ans = (ans + 2 * dfs(pos + 1, mx + 1, mn) % MOD) % MOD;
        s.insert(mx);
        return ans;
    }
    if(it1 != s.end()) {
        s.erase(it1);
        ans = (ans + dfs(pos + 1, mx, mn + 1) % MOD) % MOD;
        s.insert(mx);
    }
    if(it2 != s.end()) {
        s.erase(it2);
        ans = (ans + dfs(pos + 1, mx + 1, mn) % MOD) % MOD;
        s.insert(mn);
    }
    return ans;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.insert(x);
    }
    cout << dfs(1, 0, 0);
    return 0;
}