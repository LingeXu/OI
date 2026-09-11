#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int t, sx, sy, ax, ay, bx, by;
void solve() {
    cin >> sx >> sy >> ax >> ay >> bx >> by;
    double a_end = ax - (double)sx / sy * ay, b_end = bx - (double)sx / sy * by;
    if(a_end * b_end <= 0) 
        cout << fixed << setprecision(15) << 0.0 << ' ';
    else    cout << fixed << setprecision(15) << min(fabs(a_end), fabs(b_end)) << ' ';
    if(sx == 0) {
        cout << fixed << setprecision(15) << max(fabs(ax), fabs(bx)) << '\n';
        return;
    }
    ll R = 1LL * ax * ax + 1LL * ay * ay;
    ll S = 1LL * sx * sx + 1LL * sy * sy;
    double r = sqrt(R); 
    double px;
    if(sx < 0)
        px = fabs((double)sy * r / sqrt(S)); 
    else    px = -fabs((double)sy * r / sqrt(S));
    double py = sqrt(r * r - px * px);
    if(bx <= px && px <= ax) 
        cout << fixed << setprecision(15) << fabs(px - (double)sx / sy * py) << '\n';
    else    cout << fixed << setprecision(15) << max(fabs(a_end), fabs(b_end)) << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while(t--)    solve();
    return 0;
}