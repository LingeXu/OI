#include <bits/stdc++.h>
using namespace std;
int t;
void solve() {
    string s;
    int k;
    cin >> s >> k;
    string pat = "Rounddo";
    for(int i = 1; i <= k; i++)
        pat += 'g';
    s += s;
    int pos = -1, n = (int)s.size(), cnt = 0;
    while(pos < n && (int)s.find(pat, pos + 1) != - 1) {
        pos = (int)s.find(pat, pos + 1);
        cnt++;
    }
    if(cnt == 0) 
        cout << 0 << '\n';
    else if(cnt == 1)
        cout << ((int)s.size() >> 1) - (int)pat.size() + 1 << '\n';
    else if(cnt == 2)
        cout << ((int)s.size() >> 1) - (6 + k) << '\n';
    else    cout << ((int)s.size() >> 1) << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while(t--) 
        solve();
    return 0;
}