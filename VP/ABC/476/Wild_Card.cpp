#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    string s, t;
    cin >> n >> s >> t;
    bool ok = true;
    for(int i = 0; i < n; i++) {
        if(t[i] == '*')
            continue;
        else {
            if(s[i] != t[i]) {
                ok = false;
                break;
            }
        }
    }
    if(ok) {
        cout << "Yes\n";
    }
    else    cout << "No\n";
    return 0;
}