#include <bits/stdc++.h>
using namespace std;
int t;
string a, b;
vector<int> prefix_a, prefix_b;
void solve() {
    prefix_a.clear();
    prefix_b.clear();
    cin >> a >> b;
    int pre_a[(int)a.size() + 1][10], pre_b[(int)b.size() + 1][10], last_a[10], last_b[10];
    memset(pre_a, 0, sizeof(pre_a));
    memset(pre_b, 0, sizeof(pre_b));
    memset(last_a, 0, sizeof(last_a));
    memset(last_b, 0, sizeof(last_b));
    prefix_a.push_back(0);
    for(int i = 0; i < (int)a.size(); i++) {
        int num = (prefix_a.back() + a[i] - '0') % 10;
        prefix_a.push_back(num);
        for(int j = 0; j < 10; j++)
            pre_a[i + 1][(num + 10 - j) % 10] = last_a[j];
        last_a[num] = i + 1;
    }
    prefix_b.push_back(0);
    for(int i = 0; i < (int)b.size(); i++) {
        int num = (prefix_b.back() + b[i] - '0') % 10;
        prefix_b.push_back(num);
        for(int j = 0; j < 10; j++)
            pre_b[i + 1][(num + 10 - j) % 10] = last_b[j];
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

    int dp[(int)a.size() + 1][(int)b.size() + 1];
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= (int)a.size(); i++) {
        for(int j = 1; j <= (int)b.size(); j++) {
            if(prefix_a[i] == prefix_b[j])  dp[i][j] = 1;
            for(int m = 0; m < 10; m++)
                if(pre_a[i][m] != 0 && pre_b[j][m] != 0)
                    dp[i][j] = max(dp[i][j], dp[pre_a[i][m]][pre_b[j][m]] + 1);
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