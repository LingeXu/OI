#include <bits/stdc++.h>
#define N 200020
typedef long long ll;
using namespace std;
int t, n, q;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        vector<int> a(n);
        set<int> s;
        map<int, int> mp;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            s.insert(a[i]);
            mp[a[i]]++;
        }
        cin >> q;
        for(int i = 1; i <= q; i++) {
            ll x, y, cnt = 0;
            cin >> x >> y;
            for(int num : s) {
                if(1LL * num * (x - num) == y) {
                    if(num != x - num)
                        cnt += 1LL * mp[num] * mp[x - num];
                    else    cnt += 1LL * mp[num] * (mp[num] - 1);
                }
            }
            cout << (cnt >> 1) << ' ';
        }
        cout << '\n';
    }
    return 0;
}