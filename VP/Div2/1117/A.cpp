#include <bits/stdc++.h>
using namespace std;
int t, n, m;
void solve() {
    cin >> n >> m;
    bool exist[26];
    memset(exist, 0, sizeof(exist));
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s; 
        char c = s[0];
        if(c >= 'a' && c <= 'z') {
            int idx = c - 'a';
            exist[idx] = true;
        }
    }
    for(int i = 0; i < m; i++) {
        string s;
        cin >> s;
        for(char c : s) {
            if(c >= 'A' && c <= 'Z') {
                int idx = c - 'A';
                if(!exist[idx]) {
                    cout << "NO\n";
                    return;
                }
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