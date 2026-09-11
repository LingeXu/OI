#include <bits/stdc++.h>
#define int long long
using namespace std;
int t, n;
void solve() {
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int mx = 0, need = 0;
    vector<int> s;
    for(int i = 0; i < n; i++) {
        if(i == 0)  mx = a[i];
        else {
            if(a[i] > mx)  mx = a[i];
            else {
                s.push_back(i);
                need = max(need, mx - a[i]);
            }
        }
    }
    for(auto it = s.begin(); it != s.end(); it++)
        a[*it] += need;

    //for(int i = 0; i <= n - 1; i++)  cout << a[i] << ' ';

    for(int i = 0; i < n - 1; i++) {
        if(a[i] > a[i + 1]) {
            cout << "NO" << '\n';
            return;
        }
    }
    cout << "YES" << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--)  solve();
    return 0;
}