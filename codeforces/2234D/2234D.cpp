#include <bits/stdc++.h>
#define int long long
using namespace std;
int t, n, k;
string s1, s2;
void solve() {
    cin >> n >> k >> s1 >> s2;
    int x1 = 0, y1 = 0;
    for(char c : s1) {
        if(c == '0')    x1++;
        else    y1++;
    }
    int ans1 = x1 * y1;
    int x2 = 0, y2 = 0;
    for(char c : s2) {
        if(c == '0')    x2++;
        else    y2++;
    }
    int ans2 = x2 * y2;
    int x3 = 0, y3 = 0;
    for(int i = 0; i < n; i++) {
        if(s1[i] == s2[i])  x3++;
        else    y3++;
    }
    int ans3 = x3 * y3;
    int cnt3 = ((1 << k) + 1) / 3;
    int cnt = (((1 << k) + 1) - cnt3) / 2;
    cout << cnt3 * ans3 + cnt * (ans1 + ans2) << '\n';
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while(t--)  solve();
    return 0;
}