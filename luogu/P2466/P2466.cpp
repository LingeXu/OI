#include <bits/stdc++.h>
#define N 1010
using namespace std;
int n, x0, id;
double original_score = 0;
double dp[N][N][2];
struct stuff {
    int x, y, v;
} s[N];
bool cmp(stuff a, stuff b) {
    return a.x < b.x;
}
double loss_per_second(int l, int r) {
    double res = 0;
    for(int i = 0; i <= n; i++)
        if(i < l || i > r)
            res += s[i].v;
    return res / 1000;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> x0;
    for(int i = 1; i <= n; i++) 
        cin >> s[i].x;
    for(int i = 1; i <= n; i++) {
        cin >> s[i].y;
        original_score += 1.0 * s[i].y / 1000;
    }
    for(int i = 1; i <= n; i++)
        cin >> s[i].v;
    s[0] = {x0, 0, 0};
    sort(s, s + n + 1, cmp);
    for(int i = 0; i <= n; i++)
        if(s[i].x == x0)
            id = i;
    for(int i = 0; i <= n; i++)
        for(int j = i; j <= n; j++)
            dp[i][j][0] = dp[i][j][1] = 1e10;
    dp[id][id][0] = dp[id][id][1] = 0;
    for(int len = 1; len < n + 1; len++) {
        for(int i = 0; i + len - 1 <= n; i++) {
            int j = i + len - 1;
            if(dp[i][j][0] == 1e10 && dp[i][j][1] == 1e10)    continue;
            double lps = loss_per_second(i, j);
            if(i - 1 >= 0)
                dp[i - 1][j][0] = min(dp[i - 1][j][0], min(dp[i][j][0] + lps * (s[i].x - s[i - 1].x), dp[i][j][1] + lps * (s[j].x - s[i - 1].x)));
            if(j + 1 <= n)
                dp[i][j + 1][1] = min(dp[i][j + 1][1], min(dp[i][j][0] + lps * (s[j + 1].x - s[i].x), dp[i][j][1] + lps * (s[j + 1].x - s[j].x)));
        }
    }
    cout << fixed << setprecision(3) << original_score - min(dp[0][n][0], dp[0][n][1]);
    return 0;
}