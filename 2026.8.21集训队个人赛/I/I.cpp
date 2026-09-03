#include <bits/stdc++.h>
using namespace std;
int t;
string s;
int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--) {
        cin >> s;
        int cnt = 0;
        int ok1 = 0, ok2 = 0;
        for(char c : s) {
            if(c == '(')    ok1++;
            if(c == '[')    ok2++;
            if(c == ')' && ok1 > 0) {
                cnt++;
                ok1--;
            }
            if(c == ']' && ok2 > 0) {
                cnt++;
                ok2--;
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}