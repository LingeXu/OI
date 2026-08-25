#include <bits/stdc++.h>
using namespace std;
int n, q;
map<int, int> mp;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) {
        a[i] = i;
        mp[i] = i;
    }
    while(q--) {
        int val;
        cin >> val;
        int pos = mp[val];
        if(pos != n) {
            swap(a[pos], a[pos + 1]);
            mp[a[pos]] = pos;
            mp[a[pos + 1]] = pos + 1;
        }
        else {
            swap(a[n - 1], a[n]);
            mp[a[n - 1]] = n - 1;
            mp[a[n]] = n;
        }
    }
    for(int i = 1; i <= n; i++)
        cout << a[i] << ' ';
    return 0;
}