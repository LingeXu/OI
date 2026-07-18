#include <bits/stdc++.h>
#define N 150005
using namespace std;
int n;
int dp[N][2];
struct interval {
    int x, y, prior;
} a[N];
bool cmp(interval a, interval b) {
    return a.y < b.y || (a.y == b.y && a.x < b.x);
}
bool check(int x, int id) {
    return a[x].y < a[id].x;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y;
        //a[i].prior = -1;
    }
    sort(a, a + n, cmp);
    for(int i = 0; i < n; i++) {
        int l = 0, r = i - 1, ans = -1;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(check(mid, i)) {
                ans = mid;
                l = mid + 1;
            }
            else    r = mid - 1;
        }
        a[i].prior = ans;
    }
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i < n; i++) {
        if(a[i].prior != -1)
            dp[i][1] = max(dp[a[i].prior][0], dp[a[i].prior][1]) + a[i].y - a[i].x + 1;
        else    dp[i][1] = a[i].y - a[i].x + 1;
        if(i - 1 >= 0)
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        else    dp[i][0] = 0;
    }
    cout << max(dp[n - 1][0], dp[n - 1][1]);
    return 0;
}