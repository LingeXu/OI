#include <bits/stdc++.h>
#define F 110
#define V 110
typedef long long ll;
using namespace std;
int f, v, id;
ll ans = -0x3f3f3f3f3f3f3f3f;
int a[F][V];
vector<int> idx;
struct inf {
    ll val;
    int pre;
} dp[F][V];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> f >> v;
    for(int i = 1; i <= f; i++)
        for(int j = 1; j <= v; j++)
            cin >> a[i][j];
    for(int i = 0; i < v - (f - 1); i++)
        dp[0][i].val = 0;
    for(int i = 1; i <= f; i++)
        for(int j = 1; j <= v; j++)
            dp[i][j].val = -0x3f3f3f3f3f3f3f3f;
    for(int i = 1; i <= f; i++) {
        for(int j = i; j <= v - (f - i); j++) {
            for(int k = i - 1; k < j; k++) {
                if(dp[i - 1][k].val + 1LL * a[i][j] > dp[i][j].val) {
                    dp[i][j].val = dp[i - 1][k].val + 1LL * a[i][j];
                    dp[i][j].pre = k;
                }
            }
        }
    }
    for(int i = f; i <= v; i++) {
        if(dp[f][i].val > ans) {
            id = i;
            ans = dp[f][i].val;
        }
    }
    cout << ans << '\n';
    for(int i = f; i >= 1; i--) {
        idx.push_back(id);
        id =  dp[i][id].pre;
    }
    reverse(idx.begin(), idx.end());
    for(int i = 0; i < idx.size(); i++)
        cout << idx[i] << ' ';
    return 0;
}