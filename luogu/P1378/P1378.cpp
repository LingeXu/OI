#include <bits/stdc++.h>
#define N 7
const double PI = 3.1415926;
using namespace std;
int n, x1, y1_, x2, y2;
int x, y;
double s, occupied= 0;
double ans = 4000000;
bool used[N];
struct point {
    int x, y;
    double r;
}p[N];
double GetR(int i) {
    double res = min(min(abs(x1 - p[i].x), abs(x2 - p[i].x)), min(abs(y1_ - p[i].y), abs(y2 - p[i].y)));
    for(int j = 1; j <= n; j++)
        if(j != i &&used[j])
            res = min(res, max(0.0, sqrt((p[i].x - p[j].x) * (p[i].x - p[j].x) + (p[i].y - p[j].y) * (p[i].y - p[j].y)) - p[j].r));
    return res;
}
void dfs(int u) {
    if(u == n) {
        ans = min(ans, s - occupied);
        return;
    }
    for(int i = 1; i <= n; i++) {
        if(!used[i]) {
            used[i] = true;
            p[i].r = GetR(i);
            occupied += PI * p[i].r * p[i].r;
            dfs(u + 1);
            used[i] = false;
            occupied -= PI * p[i].r * p[i].r;
            p[i].r = 0;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cin >> x1 >> y1_ >> x2 >> y2;
    s = (double)abs((x2 - x1) * (y2 - y1_));
    for(int i = 1; i <= n; i++) 
        cin >> p[i].x >> p[i].y;
    memset(used, 0,sizeof(used));
    dfs(0);
    cout << (int)(ans + 0.5);  
    return 0;
}