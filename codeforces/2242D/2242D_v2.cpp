#include <bits/stdc++.h>
#define A 5050
#define B 5050
using namespace std;
int t;
string a, b;
vector<int> prefix_a, prefix_b;
void solve() {
    prefix_a.clear();
    prefix_b.clear();
    cin >> a >> b;
    int dp[(int)a.size() + 1][(int)b.size() + 1];
    memset(dp, 0, sizeof(dp));
    prefix_a.push_back(0);
    for(int i = 0; i < (int)a.size(); i++)
        prefix_a.push_back((prefix_a.back() + a[i] - '0') % 10);
    prefix_b.push_back(0);
    for(int i = 0; i < (int)b.size(); i++)
        prefix_b.push_back((prefix_b.back() + b[i] - '0') % 10);
    for(int i = 1; i <= (int)a.size(); i++) {
        for(int j = 1; j <= (int)b.size(); j++) {
            if(prefix_a[i] != prefix_b[j]) {
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = 1;
            for(int m = 1; m < i; m++) 
                for(int n = 1; n < j; n++) 
                    if((prefix_a[i] + 10 - prefix_a[m]) % 10 == (prefix_b[j] + 10 - prefix_b[n]) % 10 && dp[m][n] != 0) 
                        dp[i][j] = max(dp[i][j], dp[m][n] + 1);
        }
    }
    int ans = dp[(int)a.size()][(int)b.size()];
    cout << (ans > 0 ? ans : -1) << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while(t--)  solve();
    return 0;
}