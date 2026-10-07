#include <bits/stdc++.h>
using namespace std;
int n;
string s;
void solve() {
    cin >> n >> s;
    s += s;

    //cout << "s = " << s << '\n';

    int j, ans = 0;
    for(int i = 0; i < 2 * n; i = j) {
        if(s[i] != '0') {
            j = i + 1;
            continue;
        }
        j = i;
        int cur = 0;
        while(j < 2 * n && s[j] == '0') {
            cur++;
            j++;
        }
        ans = max(ans, cur);
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)  solve();
    return 0;
}