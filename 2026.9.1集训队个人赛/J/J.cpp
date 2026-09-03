#include <bits/stdc++.h>
using namespace std;
int n, a, b;
string s, t;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> a >> b >> s >> t;
    int lack1 = 0, lack2 = 0, cnt = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '0') lack1++;
        if(t[i] == '0') lack2++;
        if(s[i] == '0' && t[i] == '0')  cnt++;
    }
    if(lack1 == 0 || lack2 == 0) {
        cout << fixed << setprecision(10) << (long double)n << '\n';
        return 0;
    }
    long double ans = n;
    ans -= (long double)cnt * (lack1 - a) * (lack2 - b) / ((long double)lack1 * lack2);
    cout << fixed << setprecision(10) << ans << '\n';
    return 0;
}