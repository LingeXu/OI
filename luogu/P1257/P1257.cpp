#include <bits/stdc++.h>
#define N 10010
using namespace std;
int n;
struct Point {
    double x, y;
}p[N], tmp[N];
bool cmp_x(Point a, Point b) {
    return a.x < b.x;
}
bool cmp_y(Point a, Point b) {
    return a.y < b.y;
}
double solve(int l, int r) {
    if(l >= r)  return 1e12;
    int mid = l + (r - l) / 2;
    double mid_x = p[mid].x;
    double left_ans = solve(l, mid);
    double right_ans = solve(mid + 1, r);
    double ans = min(left_ans, right_ans);
    int k = 0;
    for(int i = l; i <= r; i++)
        if(abs(p[i].x - mid_x) <= ans)
            tmp[k++] = p[i];
    sort(tmp, tmp + k, cmp_y);
    for(int i = 0; i < k; i++)
        for(int j = i + 1; j < k && tmp[j].y - tmp[i].y <= ans; j++)
            ans = min(ans, sqrt((tmp[j].x - tmp[i].x) * (tmp[j].x - tmp[i].x) + (tmp[j].y - tmp[i].y) * (tmp[j].y - tmp[i].y)));
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> p[i].x >> p[i].y;
    sort(p, p + n, cmp_x);
    cout << fixed << setprecision(4) << solve(0, n - 1);
    return 0;
}