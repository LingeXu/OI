#include <bits/stdc++.h>
#define N 100010
using namespace std;
int n;
double ans = 0;
double a[N], b[N];
double a_sum[N], b_sum[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    sort(a, a + n, greater<double>());
    sort(b, b + n, greater<double>());
    for(int i = 1; i <= n; i++) {
        a_sum[i] = a_sum[i - 1] + a[i - 1];
        b_sum[i] = b_sum[i - 1] + b[i - 1];
    }
    int x_cnt = 0;
    int y_cnt = 0;
    while(x_cnt <= n && y_cnt <= n) {
        double cur = min(a_sum[x_cnt], b_sum[y_cnt]) - (x_cnt + y_cnt);
        ans = max(ans, cur);
        if(b_sum[y_cnt] >= a_sum[x_cnt])    x_cnt++;
        else    y_cnt++;
    }
    cout << fixed << setprecision(4) << ans;
    return 0;
}