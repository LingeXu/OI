#include <bits/stdc++.h>
using namespace std;
int t, n;
void solve() {
    cin >> n;
    vector<int> a(n), b(n), c(n), pos_b(n + 1), pos_c(n + 1);
    set<int> s;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++) {
        cin >> b[i];
        pos_b[b[i]] = i;
    }
    for(int i = 0; i < n; i++) {
        cin >> c[i];
        pos_c[c[i]] = i;
    }
    int mx_b = -1, mx_c = -1;
    for(int i = 0; i < n; i++) {
        int cur = a[i];
        mx_b = max(mx_b, pos_b[cur]);
        mx_c = max(mx_c, pos_c[cur]);
        if(mx_b == i || mx_c == i) 
            s.insert(i);
    }
    int mx = -1;
    for(int i = 0; i < n; i++) {
        int cur = b[i];
        mx = max(mx, pos_c[cur]);
        if(mx == i)
            s.insert(i);
    }
    cout << (int)s.size() << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--)  solve();
    return 0;
}