#include <bits/stdc++.h>
using namespace std;
int t, n, k;
void solve() {
    cin >> n >> k;
    set<int> s;
    unordered_map<int, int> mp, bad;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mp[x] = 1;
        bad[x] = 0;
        s.insert(x);
    }
    vector<int> ans;
    for(int num : s) {
        if(bad[num] == 1)   continue;
        ans.push_back(num);
        for(int i = num; i <= k; i += num) {
            if(!mp.count(i)) {
                cout << -1 << '\n';
                return;
            }
            bad[i] = 1;
        }
    }
    cout << (int)ans.size() << '\n';
    for(int num : ans)
        cout << num << ' ';
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while(t--)  solve();
    return 0;
}