#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    string s;
    int n;
    char c;
    cin >> t;
    while(t--) {
        cin >> n >> c >> s;
        int ans = 0;
        for(int i = 0; i <= (n - 1) / 2; i++) {
            if(s[i] == s[n - i - 1])    continue;
            else {
                if(s[i] == c || s[n - i - 1] == c)
                    ans++;
                else    ans += 2;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}