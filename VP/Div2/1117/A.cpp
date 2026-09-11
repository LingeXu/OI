#include <bits/stdc++.h>
using namespace std;
int t, n, m;
void solve() {
    cin >> n >> m;
    int exist[26];
    memset(exist, 0, sizeof(exist));
    for(int i = 0; i < n; i++) {
        string s;
        if (!(cin >> s)) return;   
        char c = s[0];
        exist[tolower(c) - 'a'] = true;
    }
    for(int i = 0; i < m; i++) {
        string s;
        if (!(cin >> s)) return;
        for(char c : s) {
            int idx = tolower(c) - 'a';
 
            if(!exist[idx]) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while(t--)  solve();
    return 0;
}