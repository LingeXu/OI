#include <bits/stdc++.h>
using namespace std;
int t;
string a, b;
vector<int> prefix_a, prefix_b;
void solve() {
    prefix_a.clear();
    prefix_b.clear();
    cin >> a >> b;
    int n = (int)a.size(), m = (int)b.size();
    vector<int> last_a(10, -1), last_b(10, -1);
    vector< vector<int> > pre_a(n + 1, vector<int>(10, -1)), pre_b(m + 1, vector<int>(10, -1));
    prefix_a.push_back(0);
    for(int i = 0; i < n; i++) {
        int num = (prefix_a.back() + a[i] - '0') % 10;
        prefix_a.push_back(num);
        for(int j = 0; j < 10; j++)
            pre_a[i + 1][j] = last_a[(num + 10 - j) % 10];
        last_a[num] = i + 1;
    }
    prefix_b.push_back(0);
    for(int i = 0; i < m; i++) {
        int num = (prefix_b.back() + b[i] - '0') % 10;
        prefix_b.push_back(num);
        for(int j = 0; j < 10; j++)
            pre_b[i + 1][j] = last_b[(num + 10 - j) % 10];
        last_b[num] = i + 1;
    }

    /*for(int i = 0; i <= (int)a.size(); i++)
        cout << prefix_a[i] << ' ';
    cout << '\n';
    for(int i = 1; i <= (int)a.size(); i++) {
        for(int m = 0; m < 10; m++)
            cout << pre_a[i][m] << ' ';
        cout << '\n';
    }
    cout << '\n';*/

    vector< vector<int> > dp(n + 1, vector<int>(m + 1, 0));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(prefix_a[i] == prefix_b[j])  dp[i][j] = 1;
            for(int m = 0; m < 10; m++)
                if(pre_a[i][m] != -1 && pre_b[j][m] != -1 && dp[pre_a[i][m]][pre_b[j][m]] != 0)
                    dp[i][j] = max(dp[i][j], dp[pre_a[i][m]][pre_b[j][m]] + 1);
        }
    }
    int ans = dp[n][m];
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