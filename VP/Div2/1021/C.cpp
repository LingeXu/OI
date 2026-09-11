#include <bits/stdc++.h>
using namespace std;
int t, n;
void solve() {
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    map<int, bool> mp;
    sort(a.begin(), a.end());
    for(int i = 0; i < n; ) {
        int cnt = 0, j = i;
        while(j < n && a[j] == a[i]) {
            cnt++;
            if(cnt == 4) {
                cout << "YES\n";
                return;
            }
            if(mp[a[i]] == true && cnt == 2) {
                cout << "YES\n";
                return;
            }
            if(mp[a[i]] == false && cnt == 2) {
                mp[a[i] + 1] = true;
                j++;
                continue;
            }
            if(mp[a[i]] == true && cnt == 1) {
                mp[a[i] + 1] = true;
                j++;
                continue;
            }
            j++;
        }
        i = j;
    }
    cout << "NO\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--)  solve();
    return 0;
}