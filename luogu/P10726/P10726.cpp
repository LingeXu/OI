#include <bits/stdc++.h>
#define N 1010
#define INF 0x3f3f3f3f
using namespace std;
int n, s, t;
struct baffle {
    int l, r, h;
    bool operator==(const baffle& other) const {
        return l == other.l && r == other.r && h == other.h;
    }
};
bool cmp(baffle x, baffle y) {
    return x.h < y.h || (x.h == y.h && x.l < y.l);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> s >> t;
    vector<baffle> b(n);
    for(int i = 0; i < n; i++) 
        cin >> b[i].l >> b[i].r >> b[i].h;
    baffle start = b[s - 1], end = b[t - 1];
    if(start.h < end.h) {
        cout << -1;
        return 0;
    }
    sort(b.begin(), b.end(), cmp);
    int start_idx, end_idx;
    for(int i = 0; i < n; i++) {
        if(b[i] == start)   start_idx = i;
        if(b[i] == end)   end_idx = i;
    }

    /*cout << start_idx << ' ' << end_idx << '\n';
    cout << '\n';*/

    int dp[N][2];
    memset(dp, 0x3f, sizeof(dp));
    dp[start_idx][0] = 0;
    dp[start_idx][1] = b[start_idx].r - b[start_idx].l;
    int ans = (start_idx == end_idx ? 0 : INF);   // s == t 时出发即在目标挡板上
    for(int i = start_idx; i >= end_idx; i--) {
        bool start_left_found = false, start_right_found = false;
        for(int j = i - 1; j >= end_idx; j--) {
            if(b[i].l >= b[j].l && b[i].l <= b[j].r && !start_left_found) {
                start_left_found = true;
                if(j == end_idx)
                    ans = min(ans, dp[i][0] + b[i].h - b[j].h);   
                dp[j][0] = min(dp[j][0], dp[i][0] + b[i].h - b[j].h + b[i].l - b[j].l);
                dp[j][1] = min(dp[j][1], dp[i][0] + b[i].h - b[j].h + b[j].r - b[i].l);
            }
            if(b[i].r >= b[j].l && b[i].r <= b[j].r && !start_right_found) {
                start_right_found = true;
                if(j == end_idx)
                    ans = min(ans, dp[i][1] + b[i].h - b[j].h);
                dp[j][0] = min(dp[j][0], dp[i][1] + b[i].h - b[j].h + b[i].r - b[j].l);
                dp[j][1] = min(dp[j][1], dp[i][1] + b[i].h - b[j].h + b[j].r - b[i].r);
            }
        }
    }
    if(ans == INF)  cout << -1;
    else    cout << ans;
    return 0;
}