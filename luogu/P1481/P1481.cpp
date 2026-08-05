#include <bits/stdc++.h>
#define N 2020
using namespace std;
int n, ans = 1;
int dp[N];
string s[N];
bool cmp(string a, string b) {
    return a.size() < b.size() || (a.size() == b.size() && a < b);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) 
        cin >> s[i];
    sort(s, s + n, cmp);
    for(int i = 0; i < n; i++) {
        dp[i] = 1;
        for(int j = 0; j < i; j++)
            if(s[j] == s[i].substr(0, s[j].size()))
                dp[i] = max(dp[i], dp[j] + 1);
        //cout << s[i] << ' ' << dp[i] << ' ';
        ans = max(ans, dp[i]);
    }
    cout << ans;
    return 0;
}