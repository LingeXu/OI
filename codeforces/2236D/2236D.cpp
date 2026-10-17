#include <bits/stdc++.h>
using namespace std;
int t, n, k;
void solve() {
    cin >> n >> k;
    vector<int> a(n);
    unordered_map<int, int> mp;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    if((int)a.size() == 1) {
        if(mp[a[0]] % 2 == 0) {
            cout << "YES\n";
            return;
        }
        cout << "NO\n";
        return;
    }
    bool ok = true;
    for(int i = 1; i < (int)a.size(); i++) {
        if(a[i] - a[i - 1] > k && mp[a[i]] % 2 == 1 && mp[a[i - 1]] % 2 == 1)   continue;
        ok = false;
        break;
    }
    if(ok)  cout << "NO\n";
    else    cout << "YES\n";

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--)  solve();
    return 0;
}