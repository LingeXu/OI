#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        map<int, bool> mp;
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(!mp.count(a[i])) {
                mp[a[i]] = true;
                cnt++;
            }
        }
        sort(a.begin(), a.end());
        auto it =lower_bound(a.begin(), a.end(), cnt);
        if(it == a.end()) {
            cout << 1000 << '\n';
        }
        else    cout << *it <<'\n';
    }
    return 0;
}