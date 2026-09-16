#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    deque<int> dq;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        dq.push_back(x);
    }
    vector<int> ans;
    for(int i = 0; i < q; i++) {
        int x;
        cin >> x;
        dq.push_back(x);
    }
    map<int, int> mp;
    while((int)ans.size() < n) {
        int cur = dq.back();
        if(mp[cur] == 1) {
            dq.pop_back();
            continue;
        }
        else {
            mp[cur]++;
            dq.pop_back();
            ans.push_back(cur);
            continue;
        }
    }
    for(int i = n - 1; i >= 0; i--)
        cout << ans[i] << ' ';
    return 0;
}