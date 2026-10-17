#include <bits/stdc++.h>
using namespace std;
int t;
string s;
void solve() {
    cin >> s;
    int n = (int)s.size();
    bool ok1 = false, ok2 = false;
    for(int i = 0; i < n; ) {
        int j = i, cnt = 0;
        while(j < n && s[i] == s[j]) {
            cnt++;
            j++;
        }
        if(cnt == 1 && i != 0 && i != n - 1)    ok1 = true;
        if(cnt >= 3)    ok2 = true;
        i = j;
    }
    if(!ok1 && !ok2) {
        cout << 1 << '\n';
        return;
    }
    if(ok1 && !ok2) {
        cout << 2 << '\n';
        return;
    }
    if(!ok1 && ok2) {
        cout << 2 << '\n';
        return;
    }
    cout << 3 << '\n';
    return;
    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--)  solve();
    return 0;
}