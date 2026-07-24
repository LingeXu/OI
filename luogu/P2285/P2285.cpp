#include <bits/stdc++.h>
#define N 1010
#define M 10010
using namespace std;
int n, m, ans = 0;
int dp[M];
struct inf {
    int t, x, y;
} mole[M];
int dis(int id1, int id2) {
    return abs(mole[id1].x - mole[id2].x) + abs(mole[id1].y - mole[id2].y);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++) 
        cin >> mole[i].t >> mole[i].x >> mole[i].y;
    for(int i = 1; i <= m; i++)
        dp[i] = 1;
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j < i; j++) {
            if(mole[i].t - mole[j].t >= dis(i, j))
                dp[i] = max(dp[i], dp[j] + 1); 
        }
    }
    for(int i = 1; i <= m; i++)
        ans = max(ans, dp[i]);
    cout << ans;
    return 0;
}